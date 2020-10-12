#!/bin/sh

lex lexer.l
gcc lex.yy.c -o uccompiler
cat $1 | ./uccompiler
rm lex.yy.c
rm uccompiler
