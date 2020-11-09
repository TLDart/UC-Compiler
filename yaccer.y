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

%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE  
%token RPAR SEMI ID INTLIT CHRLIT REALLIT RESERVED SIMPLECOMMENT MLCOMMENTS MLCOMMENTE ERROR

%%

test: ID ASSIGN INTLIT {printf("sucess\n");}
/* FunctionsAndDeclarations −→ (FunctionDefinition | FunctionDeclaration | Declaration) {Func-
tionDefinition | FunctionDeclaration | Declaration}
FunctionDefinition −→ TypeSpec FunctionDeclarator FunctionBody
FunctionBody −→ LBRACE [DeclarationsAndStatements] RBRACE
DeclarationsAndStatements −→ Statement DeclarationsAndStatements | Declaration Declarati-
onsAndStatements | Statement | Declaration
FunctionDeclaration −→ TypeSpec FunctionDeclarator SEMI
FunctionDeclarator −→ ID LPAR ParameterList RPAR
ParameterList −→ ParameterDeclaration {COMMA ParameterDeclaration}
ParameterDeclaration −→ TypeSpec [ID]
Declaration −→ TypeSpec Declarator {COMMA Declarator} SEMI
TypeSpec −→ CHAR | INT | VOID | SHORT | DOUBLE
Declarator −→ ID [ASSIGN Expr]
Statement −→ [Expr] SEMI
Statement −→ LBRACE {Statement} RBRACE
Statement −→ IF LPAR Expr RPAR Statement [ELSE Statement]
Statement −→ WHILE LPAR Expr RPAR Statement
Statement −→ RETURN [Expr] SEMI
Expr −→ Expr (ASSIGN | COMMA) Expr
Expr −→ Expr (PLUS | MINUS | MUL | DIV | MOD) Expr
Expr −→ Expr (OR | AND | BITWISEAND | BITWISEOR | BITWISEXOR) Expr
Expr −→ Expr (EQ | NE | LE | GE | LT | GT) Expr
Expr −→ (PLUS | MINUS | NOT) Expr
Expr −→ ID LPAR [Expr {COMMA Expr}] RPAR
Expr −→ ID | INTLIT | CHRLIT | REALLIT | LPAR Expr RPAR */
%%

void yyerror(char *msg) {
   printf ("Line %d, col %d: %s: %s\n" , 69, 69, msg , "TDB");
}
