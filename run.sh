#!/bin/sh

lex lexer.l
gcc lex.yy.c -o uccompiler
rm lex.yy.c
cat $1 | ./uccompiler
