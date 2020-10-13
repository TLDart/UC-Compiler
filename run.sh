#!/bin/sh

lex lexer.l
gcc lex.yy.c -o uccompiler
./uccompiler -l
rm lex.yy.c
rm uccompiler
