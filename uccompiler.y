/*
    Duarte Dias 2018293526
    Miguel Rabuge 2018293728

*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "functions.h"

int yylex(void);
void yyerror(char* s);

extern int lines;
extern int columns;
extern char* yytext;
extern int yyleng;
extern struct program* myprog;
int syntax_error_counter = 0;
%}

%union{
	struct info* info;
	struct oplines* opl;
    int integer;
    char* string;
    struct program* prog;
	struct tpspec* i_tsp;
    struct function_definition* i_f_def;
    struct function_declaration* i_f_dec;
    struct declaration* i_dec;
    struct parameter_list* i_param_list;
    struct function_body* i_f_body;
    struct parameter_declaration* i_param_dec;
    struct statement* i_stt;
    struct expression* i_expr;
    struct declarator* i_decl;
    struct call* i_call;
}

%type<prog> FunctionsAndDeclarations kleenClosureFDefFDecDec
%type<i_f_def> FunctionDefinition
%type<i_f_dec> FunctionDeclaration
%type<i_dec> Declaration kleenClosureCommaDeclarator
%type<i_f_body> FunctionBody DeclarationsAndStatements DeclarationsOrStatements
%type<i_param_list> ParameterList kleenClosureCommaParameterDeclaration
%type<i_param_dec> ParameterDeclaration
%type<i_stt> ErrorOrStat
%type<i_stt> Statement kleenClosureStatement
%type<i_expr> Expression 
%type<i_decl> Declarator
%type<i_call> kleenClosureCommaExpr
%type<i_tsp> TypeSpec


/* Tokens */

// Tokens which yylval (Value) is NOT necessary
%token  CHAR ELSE INT SHORT DOUBLE VOID
        LBRACE LPAR   
        RBRACE RPAR SEMI RESERVED SIMPLECOMMENT MLCOMMENTS MLCOMMENTE THEN

// Tokens which yylval (Value) is necessary    
%token <info>     CHRLIT ID REALLIT INTLIT
%token <opl> OR AND EQ NE LT GT GE PLUS MINUS MUL DIV MOD ASSIGN COMMA BITWISEAND BITWISEOR BITWISEXOR LE NOT RETURN IF WHILE

/* Associativity and Priority of Operators */

    // Based on this ref: https://www.tutorialspoint.com/cprogramming/c_operators_precedence.htm

//----------------- Lesser Priority
%right THEN ELSE
%left COMMA         // ,
%right ASSIGN       // =
%left OR            // ||
%left AND           // &&       
%left BITWISEOR     // |
%left BITWISEXOR    // ^
%left BITWISEAND    // &
%left EQ NE         // ==   !=
%left GE GT LE LT   // >=   >   <=  <
%left MINUS PLUS    // -    +
%left MUL DIV MOD   // *    /   %
%right NOT          // !1

%left OP1 error_aux // Auxiliary
//----------------- Higher Priority

%%
// test: ID ASSIGN INTLIT {printf("sucess\n");}

FunctionsAndDeclarations:       FunctionDefinition kleenClosureFDefFDecDec          {if(syntax_error_counter == 0){$$=myprog=insert_program_func_def($1,$2);}}
        |                       FunctionDeclaration kleenClosureFDefFDecDec         {if(syntax_error_counter == 0){$$=myprog=insert_program_func_dec($1,$2);}}
        |                       Declaration kleenClosureFDefFDecDec                 {if(syntax_error_counter == 0){$$=myprog=insert_program_dec($1,$2);}}
        ;

kleenClosureFDefFDecDec:        /* Epsilon */                                       {if(syntax_error_counter == 0){$$= NULL;}}
        |                       kleenClosureFDefFDecDec FunctionDefinition          {if(syntax_error_counter == 0){$$=insert_program_func_def_rem($1,$2);}}
        |                       kleenClosureFDefFDecDec FunctionDeclaration         {if(syntax_error_counter == 0){$$=insert_program_func_dec_rem($1,$2);}}
        |                       kleenClosureFDefFDecDec Declaration                 {if(syntax_error_counter == 0){$$=insert_program_dec_rem($1,$2);}}
        ;

FunctionDefinition :            TypeSpec ID LPAR ParameterList RPAR FunctionBody    {if(syntax_error_counter == 0){$$=insert_function_definition($1,$2,$4,$6);}}
        ;

FunctionBody:                   LBRACE RBRACE                                       {if(syntax_error_counter == 0){$$=NULL;}}
        |                       LBRACE DeclarationsAndStatements RBRACE             {if(syntax_error_counter == 0){$$=$2;}}
        ;

DeclarationsAndStatements:      DeclarationsOrStatements                            {if(syntax_error_counter == 0){$$=$1;}}
        |                       DeclarationsAndStatements DeclarationsOrStatements  {if(syntax_error_counter == 0){$$=insert_f_body_multiple($1,$2);}}
        ;
DeclarationsOrStatements:       Statement                                           {if(syntax_error_counter == 0){$$=insert_f_body_statement($1);} }
        |                       Declaration                                         {if(syntax_error_counter == 0){$$=insert_f_body_declaration($1);} }
        ;

FunctionDeclaration:            TypeSpec ID LPAR ParameterList RPAR SEMI            {if(syntax_error_counter == 0){$$=insert_function_declaration($1,$2,$4);}}
        ;

ParameterList:    ParameterDeclaration kleenClosureCommaParameterDeclaration        {if(syntax_error_counter == 0){$$=insert_param_list($1, $2);}}
        ;
kleenClosureCommaParameterDeclaration:  /* Epsilon */                               {if(syntax_error_counter == 0){$$=NULL;}}
        |       kleenClosureCommaParameterDeclaration COMMA ParameterDeclaration    {if(syntax_error_counter == 0){$$=insert_param_list_rem($1,$3);}}
        ;

ParameterDeclaration:           TypeSpec ID                                         {if(syntax_error_counter == 0){$$=insert_param_dec($1,$2);}}
        |                       TypeSpec                                            {if(syntax_error_counter == 0){$$=insert_param_dec($1, NULL);}}
        ;


Declaration:      TypeSpec Declarator kleenClosureCommaDeclarator SEMI              {if(syntax_error_counter == 0){$$=insert_dec($1,$2,$3);}}
        |         error SEMI                                                        {if(syntax_error_counter == 0){$$=NULL;}}
        ;
kleenClosureCommaDeclarator: /* Epsilon */                                          {if(syntax_error_counter == 0){$$=NULL;}}
        |            kleenClosureCommaDeclarator COMMA Declarator                   {if(syntax_error_counter == 0){$$=insert_dec_rem($1,$3);}}
        ;

TypeSpec:               CHAR                                                        {if(syntax_error_counter == 0){$$=insert_tpspec(0, lines, columns - yyleng);} }
        |               INT                                                         {if(syntax_error_counter == 0){$$=insert_tpspec(1, lines, columns - yyleng);}}
        |               VOID                                                        {if(syntax_error_counter == 0){$$=insert_tpspec(2, lines, columns - yyleng);}}
        |               SHORT                                                       {if(syntax_error_counter == 0){$$=insert_tpspec(3, lines, columns - yyleng);}}
        |               DOUBLE                                                      {if(syntax_error_counter == 0){$$=insert_tpspec(4, lines, columns - yyleng);}}
        ;

Declarator:             ID                                                          {if(syntax_error_counter == 0){$$=insert_decl($1, NULL);}}
        |               ID ASSIGN Expression                                        {if(syntax_error_counter == 0){$$=insert_decl($1,$3);}}
        ;

Statement:              Expression SEMI                                             {if(syntax_error_counter == 0){$$=insert_expr_statement($1);}}
        |               SEMI                                                        {if(syntax_error_counter == 0){$$=NULL;}}
        |               LBRACE kleenClosureStatement RBRACE                         {if(syntax_error_counter == 0){$$=insert_statlist($2);}}
        |               IF LPAR Expression RPAR ErrorOrStat  %prec THEN             {if(syntax_error_counter == 0){$$=insert_if_statement($3,$5,NULL,$1);}}
        |               IF LPAR Expression RPAR ErrorOrStat ELSE ErrorOrStat        {if(syntax_error_counter == 0){$$=insert_if_statement($3,$5,$7,$1);}}
        |               WHILE LPAR Expression RPAR ErrorOrStat                      {if(syntax_error_counter == 0){$$=insert_while_statement($3,$5,$1);}}
        |               RETURN SEMI                                                 {if(syntax_error_counter == 0){$$=insert_return(NULL,$1);}}
        |               RETURN Expression SEMI                                      {if(syntax_error_counter == 0){$$=insert_return($2,$1);}}
        |               LBRACE error RBRACE                                         {if(syntax_error_counter == 0){$$=NULL;}}
        |               LBRACE RBRACE                                               {if(syntax_error_counter == 0){$$=NULL;}}
        ;
kleenClosureStatement:  ErrorOrStat                                                 {if(syntax_error_counter == 0){$$=$1;}}
        |               kleenClosureStatement ErrorOrStat                           {if(syntax_error_counter == 0){$$=insert_statement($1,$2);}}
        ;
ErrorOrStat:            error SEMI                                                  {if(syntax_error_counter == 0){$$=NULL;}}
        |               Statement                                                   {if(syntax_error_counter == 0){$$=$1;}}
        ;

Expression:             Expression OR Expression                                    {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,0,$3);}}
        |               Expression AND Expression                                   {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,1,$3);}}
        |               Expression EQ Expression                                    {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,2,$3);}}
        |               Expression NE Expression                                    {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,3,$3);}}
        |               Expression LT Expression                                    {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,4,$3);}}
        |               Expression GT Expression                                    {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,5,$3);}}
        |               Expression GE Expression                                    {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,6,$3);}}
        |               Expression PLUS Expression                                  {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,7,$3);}}
        |               Expression MINUS Expression                                 {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,8,$3);}}
        |               Expression MUL Expression                                   {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,9,$3);}}
        |               Expression DIV Expression                                   {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,10,$3);}}
        |               Expression MOD Expression                                   {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,11,$3);}}
        |               Expression ASSIGN Expression                                {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,12,$3);}}
        |               Expression COMMA Expression                                 {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,13,$3);}}
        |               Expression BITWISEAND Expression                            {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,14,$3);}}
        |               Expression BITWISEXOR Expression                            {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,15,$3);}}
        |               Expression BITWISEOR Expression                             {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,16,$3);}}
        |               Expression LE Expression                                    {if(syntax_error_counter == 0){$$=insert_expression_op2($1,$2,17,$3);}}

        |               NOT Expression                                              {if(syntax_error_counter == 0){$$=insert_expression_op1(0,$1,$2);}}
        |               MINUS Expression    %prec OP1                               {if(syntax_error_counter == 0){$$=insert_expression_op1(1,$1,$2);}}
        |               PLUS Expression     %prec OP1                               {if(syntax_error_counter == 0){$$=insert_expression_op1(2,$1,$2);}}

        |               ID LPAR Expression kleenClosureCommaExpr RPAR               {if(syntax_error_counter == 0){$$=insert_expression_call($1,$3,$4);}}
        |               ID LPAR RPAR                                                {if(syntax_error_counter == 0){$$=insert_expression_call($1,NULL,NULL);}}

        |               CHRLIT                                                      {if(syntax_error_counter == 0){$$=insert_expression_terminal($1,1);}}
        |               ID                                                          {if(syntax_error_counter == 0){$$=insert_expression_terminal($1,2);}}
        |               INTLIT                                                      {if(syntax_error_counter == 0){$$=insert_expression_terminal($1,5);}}
        |               REALLIT                                                     {if(syntax_error_counter == 0){$$=insert_expression_terminal($1,7);}}

        |               LPAR Expression RPAR                                        {if(syntax_error_counter == 0){$$=$2;}}
        |               ID LPAR error RPAR                                          {if(syntax_error_counter == 0){$$=NULL;}}
        |               LPAR error RPAR                                             {if(syntax_error_counter == 0){$$=NULL;}}
        

kleenClosureCommaExpr:   /* Epsilon */ %prec COMMA                                  {if(syntax_error_counter == 0){$$=NULL;}}
        |               kleenClosureCommaExpr COMMA Expression                      {if(syntax_error_counter == 0){$$=insert_expression_kleen($1,$3);}}  
        ;


%%

void yyerror(char *msg) {
        //printf("columns = %d; yyleng = %d\n",columns,yyleng);
        printf ("Line %d, col %d: %s: %s\n" , lines, columns - yyleng, msg , yytext);
        ++syntax_error_counter;
}
