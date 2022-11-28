# UC-Compiler
Compiler for a sub-language of C, called UC, made for academic purposes

## Notes
The UC language is a subset of the C language, missing in some key features (but making it easier to create a compiler to).


## Files
* uccompiler.l -> Lexer file 
* uccompiler.y -> Yacc file
Used for paring the language

* free.c 
Library used for cleanup

* printlib.c
Library focused on printing the moving parts of the application (required for the evaluation process)

* symbol_table.c
Manages the symbol table

* semantics.c
Checks if the semantics of the inserted program are correct and parses them into an AST

* functions.c
* Miscelaenous Functions

## Contributors
* [Miguel Rabuge](https://github.com/MikeLrUC)
