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
}

%type<prog> FunctionsAndDeclarations kleenClosureFDefFDecDec
%type<i_f_def> FunctionDefinition
%type<i_f_dec> FunctionDeclaration
%type<i_dec> Declaration
%type<integer> TypeSpec
%type<i_f_body> FunctionBody
%type<i_param_list> ParameterList
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
        |       LBRACE DeclarationsAndStatements RBRACE                 {$$= NULL;}
        ;

DeclarationsAndStatements:  DeclarationsOrStatements
                |           DeclarationsAndStatements DeclarationsOrStatements 
                ;
DeclarationsOrStatements:   Statement 
                |           Declaration 
                |           error SEMI      
                ;

FunctionDeclaration: TypeSpec ID LPAR ParameterList RPAR SEMI                   {$$=insert_function_declaration($1,$2,$4);}
;

ParameterList: ParameterDeclaration kleenClosureCommaParameterDeclaration       {$$=NULL;}
;
kleenClosureCommaParameterDeclaration:  /* Epsilon */
                            |           kleenClosureCommaParameterDeclaration COMMA ParameterDeclaration
                            ;

ParameterDeclaration:   TypeSpec ID
                |       TypeSpec
                ;


Declaration:   TypeSpec Declarator kleenClosureCommaDeclarator SEMI             {$$=NULL;}
        ;
kleenClosureCommaDeclarator: /* Epsilon */
                |            kleenClosureCommaDeclarator COMMA Declarator
                ;

TypeSpec: CHAR                                                                  {$$=0;}
        | INT                                                                   {$$=1;}
        | VOID                                                                  {$$=2;}
        | SHORT                                                                 {$$=3;}
        | DOUBLE                                                                {$$=4;}
        ;

Declarator: ID
        |    ID ASSIGN Expr
        ;

Statement:  Expr SEMI
            | SEMI
            | LBRACE kleenClosureStatement RBRACE;
            | IF LPAR Expr RPAR Statement  %prec THEN
            | IF LPAR Expr RPAR Statement ELSE Statement
            | WHILE LPAR Expr RPAR Statement
            | RETURN SEMI
            | RETURN Expr SEMI
            | LBRACE error RBRACE
            ;
kleenClosureStatement:  /* Epsilon */
                | kleenClosureStatement Statement
                ;

Expr:   Expr ASSIGN Expr
    |   Expr COMMA Expr

    |   Expr PLUS Expr
    |   Expr MINUS Expr
    |   Expr MUL Expr
    |   Expr DIV Expr
    |   Expr MOD Expr

    |   Expr OR Expr
    |   Expr AND Expr
    |   Expr BITWISEAND Expr
    |   Expr BITWISEOR Expr
    |   Expr BITWISEXOR Expr

    |   Expr EQ Expr
    |   Expr NE Expr
    |   Expr LE Expr
    |   Expr GE Expr
    |   Expr LT Expr
    |   Expr GT Expr

    |   PLUS Expr
    |   MINUS Expr
    |   NOT Expr

    |   ID LPAR Expr kleenClosureCommaExpr RPAR
    |   ID LPAR RPAR

    |   ID
    |   INTLIT
    |   CHRLIT
    |   REALLIT

    |   LPAR Expr RPAR
    |   ID LPAR error RPAR
    |   LPAR error RPAR
    ;

kleenClosureCommaExpr:   /* Epsilon */ %prec COMMA
        |               kleenClosureCommaExpr COMMA Expr
        ;


%%

void yyerror(char *msg) {
   printf ("Line %d, col %d: %s: %s\n" , lines, columns, msg , yytext);
   ++syntax_error_counter;
}
