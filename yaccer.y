

%%
/*  
    [...] - Opcional 
    {...} - * (zero ou mais repeticoes)
    


*/
FunctionsAndDeclarations −→ (FunctionDefinition | FunctionDeclaration | Declaration) {FunctionDefinition | FunctionDeclaration | Declaration}
FunctionDefinition −→ TypeSpec FunctionDeclarator FunctionBody
FunctionBody −→ LBRACE [DeclarationsAndStatements] RBRACE
DeclarationsAndStatements −→ Statement DeclarationsAndStatements | Declaration DeclarationsAndStatements | Statement | Declaration
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
Expr −→ ID | INTLIT | CHRLIT | REALLIT | LPAR Expr RPAR

%%