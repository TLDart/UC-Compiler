#!/bin/sh

lex lexer.l
yacc -v -d yaccer.y
gcc  -o uccompiler lex.yy.c y.tab.c
rm lex.yy.c y.tab.h y.tab.c
cat $1 | ./uccompiler
