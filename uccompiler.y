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
    int integer;
    char* string;
    struct program* prog;
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
%type<integer> TypeSpec
%type<i_f_body> FunctionBody DeclarationsAndStatements DeclarationsOrStatements
%type<i_param_list> ParameterList kleenClosureCommaParameterDeclaration
%type<i_param_dec> ParameterDeclaration
%type<i_stt> Statement kleenClosureStatement
%type<i_expr> Expression 
%type<i_decl> Declarator
%type<i_call> kleenClosureCommaExpr

/* Tokens */

// Tokens which yylval (Value) is NOT necessary
%token  CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR
        AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS
        RBRACE RPAR SEMI RESERVED SIMPLECOMMENT MLCOMMENTS MLCOMMENTE THEN

// Tokens which yylval (Value) is necessary    
%token <string>     CHRLIT ID REALLIT INTLIT

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

%left OP1           // Auxiliary 
//----------------- Higher Priority

%%
// test: ID ASSIGN INTLIT {printf("sucess\n");}

FunctionsAndDeclarations:       FunctionDefinition kleenClosureFDefFDecDec          {$$=myprog=insert_program_func_def($1,$2);}
        |                       FunctionDeclaration kleenClosureFDefFDecDec         {$$=myprog=insert_program_func_dec($1,$2);}
        |                       Declaration kleenClosureFDefFDecDec                 {$$=myprog=insert_program_dec($1,$2);}
        ;

kleenClosureFDefFDecDec:        /* Epsilon */                                       {$$=NULL;}
        |                       kleenClosureFDefFDecDec FunctionDefinition          {$$=insert_program_func_def_rem($1,$2);}
        |                       kleenClosureFDefFDecDec FunctionDeclaration         {$$=insert_program_func_dec_rem($1,$2);}
        |                       kleenClosureFDefFDecDec Declaration                 {$$=insert_program_dec_rem($1,$2);}
        ;

FunctionDefinition :            TypeSpec ID LPAR ParameterList RPAR FunctionBody    {$$=insert_function_definition($1,$2,$4,$6);}
        ;

FunctionBody:                   LBRACE RBRACE                                       {$$=NULL;} 
        |                       LBRACE DeclarationsAndStatements RBRACE             {$$=$2;}
        ;

DeclarationsAndStatements:      DeclarationsOrStatements                            {$$=$1;}
        |                       DeclarationsAndStatements DeclarationsOrStatements  {$$=insert_f_body_multiple($1,$2);} 
        ;
DeclarationsOrStatements:       Statement                                           {$$=insert_f_body_statement($1);} 
        |                       Declaration                                         {$$=insert_f_body_declaration($1);} 
        |                       error SEMI                                          {$$=insert_f_body_statement(NULL);}
        ;

FunctionDeclaration:            TypeSpec ID LPAR ParameterList RPAR SEMI            {$$=insert_function_declaration($1,$2,$4);}
        ;

ParameterList:    ParameterDeclaration kleenClosureCommaParameterDeclaration        {$$=insert_param_list($1, $2);}
        ;
kleenClosureCommaParameterDeclaration:  /* Epsilon */                               {$$=NULL;}
        |       kleenClosureCommaParameterDeclaration COMMA ParameterDeclaration    {$$=insert_param_list_rem($1,$3);}
        ;

ParameterDeclaration:           TypeSpec ID                                         {$$=insert_param_dec($1,$2);}
        |                       TypeSpec                                            {$$=insert_param_dec($1, NULL);}
        ;


Declaration:      TypeSpec Declarator kleenClosureCommaDeclarator SEMI              {$$=insert_dec($1,$2,$3);}
        ;
kleenClosureCommaDeclarator: /* Epsilon */                                          {$$=NULL;}
        |            kleenClosureCommaDeclarator COMMA Declarator                   {$$=insert_dec_rem($1,$3);}
        ;

TypeSpec:               CHAR                                                        {$$=0;}
        |               INT                                                         {$$=1;}
        |               VOID                                                        {$$=2;}
        |               SHORT                                                       {$$=3;}
        |               DOUBLE                                                      {$$=4;}
        ;

Declarator:             ID                                                          {$$=insert_decl($1, NULL);}
        |               ID ASSIGN Expression                                        {$$=insert_decl($1,$3);}
        ;

Statement:              Expression SEMI                                             {$$=insert_expr_statement($1);}
        |               SEMI                                                        {$$=NULL;}
        |               LBRACE kleenClosureStatement RBRACE                         {$$=insert_statlist($2);}        
        |               IF LPAR Expression RPAR Statement  %prec THEN               {$$=insert_if_statement($3,$5,NULL);}
        |               IF LPAR Expression RPAR Statement ELSE Statement            {$$=insert_if_statement($3,$5,$7);}
        |               WHILE LPAR Expression RPAR Statement                        {$$=insert_while_statement($3,$5);}
        |               RETURN SEMI                                                 {$$=insert_return(NULL);}
        |               RETURN Expression SEMI                                      {$$=insert_return($2);}
        |               LBRACE error RBRACE                                         {$$=NULL;}
        ;
kleenClosureStatement:  /* Epsilon */                                               {$$=NULL;}
        |               kleenClosureStatement Statement                             {$$=insert_statement($1,$2);}
        ;

Expression:             Expression OR Expression                                    {$$=insert_expression_op2($1,0,$3);}
        |               Expression AND Expression                                   {$$=insert_expression_op2($1,1,$3);}
        |               Expression EQ Expression                                    {$$=insert_expression_op2($1,2,$3);}
        |               Expression NE Expression                                    {$$=insert_expression_op2($1,3,$3);}
        |               Expression LT Expression                                    {$$=insert_expression_op2($1,4,$3);}
        |               Expression GT Expression                                    {$$=insert_expression_op2($1,5,$3);}
        |               Expression GE Expression                                    {$$=insert_expression_op2($1,6,$3);}
        |               Expression PLUS Expression                                  {$$=insert_expression_op2($1,7,$3);}
        |               Expression MINUS Expression                                 {$$=insert_expression_op2($1,8,$3);}
        |               Expression MUL Expression                                   {$$=insert_expression_op2($1,9,$3);}
        |               Expression DIV Expression                                   {$$=insert_expression_op2($1,10,$3);}
        |               Expression MOD Expression                                   {$$=insert_expression_op2($1,11,$3);}
        |               Expression ASSIGN Expression                                {$$=insert_expression_op2($1,12,$3);}
        |               Expression COMMA Expression                                 {$$=insert_expression_op2($1,13,$3);}
        |               Expression BITWISEAND Expression                            {$$=insert_expression_op2($1,14,$3);}
        |               Expression BITWISEXOR Expression                            {$$=insert_expression_op2($1,15,$3);}
        |               Expression BITWISEOR Expression                             {$$=insert_expression_op2($1,16,$3);}
        |               Expression LE Expression                                    {$$=insert_expression_op2($1,17,$3);}

        |               NOT Expression                                              {$$=insert_expression_op1(0,$2);}
        |               MINUS Expression    %prec OP1                               {$$=insert_expression_op1(1,$2);}
        |               PLUS Expression     %prec OP1                               {$$=insert_expression_op1(2,$2);}

        |               ID LPAR Expression kleenClosureCommaExpr RPAR               {$$=insert_expression_call($1,$3,$4);}
        |               ID LPAR RPAR                                                {$$=insert_expression_call($1,NULL,NULL);}

        |               CHRLIT                                                      {$$=insert_expression_terminal($1,1);}
        |               ID                                                          {$$=insert_expression_terminal($1,2);}
        |               INTLIT                                                      {$$=insert_expression_terminal($1,5);}
        |               REALLIT                                                     {$$=insert_expression_terminal($1,7);}

        |               LPAR Expression RPAR                                        {$$=$2;}
        |               ID LPAR error RPAR                                          {$$=NULL;}
        |               LPAR error RPAR                                             {$$=NULL;}
        

kleenClosureCommaExpr:   /* Epsilon */ %prec COMMA                                  {$$=NULL;}  
        |               kleenClosureCommaExpr COMMA Expression                      {$$=insert_expression_kleen($1,$3);}    
        ;


%%

void yyerror(char *msg) {
   printf ("Line %d, col %d: %s: %s\n" , lines, columns , msg , yytext);
   ++syntax_error_counter;
}
