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
        RBRACE RPAR SEMI RESERVED SIMPLECOMMENT MLCOMMENTS MLCOMMENTE

// Tokens which yylval (Value) is necessary
%token <integer>    INTLIT
%token <dfloat>     REALLIT
%token <character>  CHRLIT
%token <string>     ID

/* Associativity and Priority of Operators */ 
   
    // Based on this ref: https://www.tutorialspoint.com/cprogramming/c_operators_precedence.htm

//----------------- Lesser Priority
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
%right NOT          // !
//----------------- Higher Priority

%%
// test: ID ASSIGN INTLIT {printf("sucess\n");}
FunctionsAndDeclarations: (FunctionDefinition | FunctionDeclaration | Declaration) {FunctionDefinition | FunctionDeclaration | Declaration}
;
FunctionDefinition : TypeSpec FunctionDeclarator FunctionBody
;
FunctionBody : LBRACE [DeclarationsAndStatements] RBRACE
;
DeclarationsAndStatements : Statement DeclarationsAndStatements | Declaration DeclarationsAndStatements | Statement | Declaration
;
FunctionDeclaration : TypeSpec FunctionDeclarator SEMI
;
FunctionDeclarator : ID LPAR ParameterList RPAR
;
ParameterList : ParameterDeclaration {COMMA ParameterDeclaration}
;
ParameterDeclaration : TypeSpec [ID]
;
Declaration :   TypeSpec Declarator {COMMA Declarator} SEMI
        |       error SEMI
        ;
TypeSpec : CHAR | INT | VOID | SHORT | DOUBLE
;
Declarator : ID [ASSIGN Expr]
;

Statement:  [Expr] SEMI
            | LBRACE {Statement} RBRACE;
            | IF LPAR Expr RPAR Statement [ELSE Statement]
            | WHILE LPAR Expr RPAR Statement
            | RETURN [Expr] SEMI
            | error SEMI
            | LBRACE error RBRACE
            ;

Expr : Expr (ASSIGN | COMMA) Expr
    | Expr (PLUS | MINUS | MUL | DIV | MOD) Expr
    | Expr (OR | AND | BITWISEAND | BITWISEOR | BITWISEXOR) Expr
    | Expr (EQ | NE | LE | GE | LT | GT) Expr
    | (PLUS | MINUS | NOT) Expr
    | ID LPAR [Expr {COMMA Expr}] RPAR
    | ID | INTLIT | CHRLIT | REALLIT | LPAR Expr RPAR 
    | ID LPAR error RPAR
    | LPAR error RPAR
    ;

%%

void yyerror(char *msg) {
   printf ("Line %d, col %d: %s: %s\n" , 69, 69, msg , "TDB");
}
