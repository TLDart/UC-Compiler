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
extern struct program* myprog;
int syntax_error_counter = 0;
%}

%union{
    int integer;
    double dfloat;
    char character;
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
%type<i_expr> Expr 
%type<i_decl> Declarator
/* Tokens */

// Tokens which yylval (Value) is NOT necessary
%token  CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR
        AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS
        RBRACE RPAR SEMI RESERVED SIMPLECOMMENT MLCOMMENTS MLCOMMENTE THEN

// Tokens which yylval (Value) is necessary
%token <integer>    INTLIT
%token <dfloat>     REALLIT
%token <character>  CHRLIT
%token <string>     ID

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
//----------------- Higher Priority

%%
// test: ID ASSIGN INTLIT {printf("sucess\n");}

FunctionsAndDeclarations:   FunctionDefinition kleenClosureFDefFDecDec  {$$=myprog=insert_program_func_def($1,$2);}
                |           FunctionDeclaration kleenClosureFDefFDecDec {$$=myprog=insert_program_func_dec($1,$2);}
                |           Declaration kleenClosureFDefFDecDec         {$$=myprog=insert_program_dec($1,$2);}
                ;

kleenClosureFDefFDecDec:    /* Epsilon */ {$$= NULL;}
                |           kleenClosureFDefFDecDec FunctionDefinition  {$$=insert_program_func_def_rem($1,$2);}
                |           kleenClosureFDefFDecDec FunctionDeclaration {$$=insert_program_func_dec_rem($1,$2);}
                |           kleenClosureFDefFDecDec Declaration         {$$=insert_program_dec_rem($1,$2);}
                ;

FunctionDefinition : TypeSpec ID LPAR ParameterList RPAR FunctionBody   {$$=insert_function_definition($1,$2,$4,$6);}
;

FunctionBody:   LBRACE RBRACE                                           {$$=NULL;} 
        |       LBRACE DeclarationsAndStatements RBRACE                 {$$=$2;}
        ;

DeclarationsAndStatements:  DeclarationsOrStatements                    {$$=$1;}
                |           DeclarationsAndStatements DeclarationsOrStatements  {$$=insert_f_body_multiple($1,$2);} 
                ;
DeclarationsOrStatements:   Statement                                   {$$=insert_f_body_statement($1);} 
                |           Declaration                                 {$$=insert_f_body_declaration($1);} 
                |           error SEMI                                  {$$=NULL;}
                ;

FunctionDeclaration: TypeSpec ID LPAR ParameterList RPAR SEMI                   {$$=insert_function_declaration($1,$2,$4);}
;

ParameterList: ParameterDeclaration kleenClosureCommaParameterDeclaration       {$$=insert_param_list($1, $2);}
;
kleenClosureCommaParameterDeclaration:  /* Epsilon */                           {$$=NULL;}
                            |           kleenClosureCommaParameterDeclaration COMMA ParameterDeclaration {$$=insert_param_list_rem($1,$3);}
                            ;

ParameterDeclaration:   TypeSpec ID                                             {$$=insert_param_dec($1,$2);}
                |       TypeSpec                                                {$$=insert_param_dec($1, NULL);}
                ;


Declaration:   TypeSpec Declarator kleenClosureCommaDeclarator SEMI                     {$$=insert_dec($1,$2,$3);}
        ;
kleenClosureCommaDeclarator: /* Epsilon */                                              {$$=NULL;}
                |            kleenClosureCommaDeclarator COMMA Declarator               {$$=insert_dec_rem($1,$3);}
                ;

TypeSpec: CHAR                                                                  {$$=0;}
        | INT                                                                   {$$=1;}
        | VOID                                                                  {$$=2;}
        | SHORT                                                                 {$$=3;}
        | DOUBLE                                                                {$$=4;}
        ;

Declarator: ID                                                                  {$$=insert_decl($1, NULL);}
        |    ID ASSIGN Expr                                                     {$$=insert_decl($1,$3);}
        ;

Statement:  Expr SEMI                                                           {$$=insert_expr_statement($1);}
            | SEMI                                                              {$$=NULL;}
            | LBRACE kleenClosureStatement RBRACE                               {$$=insert_statlist($2);}        
            | IF LPAR Expr RPAR Statement  %prec THEN                           {$$=insert_if_statement($3,$5,NULL);}
            | IF LPAR Expr RPAR Statement ELSE Statement                        {$$=insert_if_statement($3,$5,$7);}
            | WHILE LPAR Expr RPAR Statement                                    {$$=insert_while_statement($3,$5);}
            | RETURN SEMI                                                       {$$=insert_return(NULL);}
            | RETURN Expr SEMI                                                  {$$=insert_return($2);}
            | LBRACE error RBRACE                                               {$$=NULL;}
            ;
kleenClosureStatement:  /* Epsilon */                                           {$$=NULL;}
                | kleenClosureStatement Statement                               {$$=insert_statement($1,$2);}
                ;

Expr:   Expr ASSIGN Expr                                                        {$$=NULL;}
    |   Expr COMMA Expr                                                         {$$=NULL;}

    |   Expr PLUS Expr                                                          {$$=NULL;}
    |   Expr MINUS Expr                                                         {$$=NULL;}
    |   Expr MUL Expr                                                           {$$=NULL;}
    |   Expr DIV Expr                                                           {$$=NULL;}
    |   Expr MOD Expr                                                           {$$=NULL;}

    |   Expr OR Expr{$$=NULL;}
    |   Expr AND Expr{$$=NULL;}
    |   Expr BITWISEAND Expr{$$=NULL;}
    |   Expr BITWISEOR Expr{$$=NULL;}
    |   Expr BITWISEXOR Expr{$$=NULL;}

    |   Expr EQ Expr{$$=NULL;}
    |   Expr NE Expr{$$=NULL;}
    |   Expr LE Expr{$$=NULL;}
    |   Expr GE Expr{$$=NULL;}
    |   Expr LT Expr{$$=NULL;}
    |   Expr GT Expr{$$=NULL;}

    |   PLUS Expr{$$=NULL;}
    |   MINUS Expr{$$=NULL;}
    |   NOT Expr{$$=NULL;}

    |   ID LPAR Expr kleenClosureCommaExpr RPAR{$$=NULL;}
    |   ID LPAR RPAR{$$=NULL;}

    |   ID{$$=NULL;}
    |   INTLIT{$$=NULL;}
    |   CHRLIT{$$=NULL;}
    |   REALLIT{$$=NULL;}

    |   LPAR Expr RPAR{$$=NULL;}
    |   ID LPAR error RPAR{$$=NULL;}
    |   LPAR error RPAR{$$=NULL;}
    ;

kleenClosureCommaExpr:   /* Epsilon */ %prec COMMA                     
        |               kleenClosureCommaExpr COMMA Expr                
        ;


%%

void yyerror(char *msg) {
   printf ("Line %d, col %d: %s: %s\n" , lines, columns, msg , yytext);
   ++syntax_error_counter;
}
