/*
    Duarte Dias 2018293526
    Miguel Rabuge 2018293728

*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int yylex(void);
void yyerror(char* s);

%}

%union{
    int integer;
    double dfloat;
    char character;
    char* string;
}

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

FunctionsAndDeclarations:   FunctionDefinition kleenClosureFDefFDecDec
                |           FunctionDeclaration kleenClosureFDefFDecDec
                |           Declaration kleenClosureFDefFDecDec
                ;

kleenClosureFDefFDecDec:    /* Epsilon */
                |           kleenClosureFDefFDecDec FunctionDefinition
                |           kleenClosureFDefFDecDec FunctionDeclaration
                |           kleenClosureFDefFDecDec Declaration
                ;

FunctionDefinition : TypeSpec FunctionDeclarator FunctionBody
;

FunctionBody:   LBRACE RBRACE
        |       LBRACE DeclarationsAndStatements RBRACE
        ;

DeclarationsAndStatements:  Statement DeclarationsAndStatements
                |           Declaration DeclarationsAndStatements
                |           Statement
                |           Declaration
                |           error SEMI
                ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI
;

FunctionDeclarator: ID LPAR ParameterList RPAR
;

ParameterList: ParameterDeclaration kleenClosureCommaParameterDeclaration
;
kleenClosureCommaParameterDeclaration:  /* Epsilon */
                            |           kleenClosureCommaParameterDeclaration COMMA ParameterDeclaration
                            ;

ParameterDeclaration:   TypeSpec ID
                |       TypeSpec
                ;


Declaration:   TypeSpec Declarator kleenClosureCommaDeclarator SEMI
        ;
kleenClosureCommaDeclarator: /* Epsilon */
                |            kleenClosureCommaDeclarator COMMA Declarator
                ;

TypeSpec: CHAR
        | INT
        | VOID
        | SHORT
        | DOUBLE
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
   printf ("Line %d, col %d: %s: %s\n" , 69, 69, msg , "TDB");
}
