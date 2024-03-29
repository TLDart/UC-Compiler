#!/bin/bash

flex uccompiler.l && 
yacc -d -v uccompiler.y && 
gcc -Wall -g lex.yy.c y.tab.c free.c functions.c print_lib.c symbol_table.c semantics.c -o uccompiler && 
rm lex.yy.c y.tab.h y.tab.c &&
cat $1 | ./uccompiler "${@:2}"