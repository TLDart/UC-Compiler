#!/bin/sh

lex lexer.l && 
yacc -d -v yaccer.y && 
gcc lex.yy.c y.tab.c -o uccompiler && 
rm lex.yy.c y.tab.h y.tab.c &&
cat $1 | ./uccompiler