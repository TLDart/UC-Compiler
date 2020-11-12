/*
    Duarte Dias 2018293526
    Miguel Rabuge 2018293728

*/

CHAR            char
ELSE            else
WHILE           while
IF              if
INT             int
SHORT           short
DOUBLE          double
RETURN          return
VOID            void
BITWISEAND      "&"
BITWISEOR       "|"
BITWISEXOR      "^"
AND             "&&"
ASSIGN          "="
MUL             "*"
COMMA           ","
DIV             "/"
EQ              "=="
GE              ">="
GT              ">"
LBRACE          "{"
LE              "<="
LPAR            "("
LT              "<"
MINUS           "-"
MOD             "%"
NE              "!="
NOT             "!"
OR              "||"
PLUS            "+"
RBRACE          "}"
RPAR            ")"
SEMI            ";"
ID              [a-zA-Z_][a-zA-Z_0-9]*
INTLIT          [0-9]+
CHRLIT          (\\n|\\t|\\\\|\\'|\\\"|\\[0-7][0-7]?[0-7]?|[^\n\'\\])\'
REALLIT         ([0-9]+"."[0-9]*((e|E)[+-]?[0-9]+)?)|("."[0-9]+((e|E)[+-]?[0-9]+)?)|([0-9]+((e|E)[+-]?[0-9]+))
RESERVED        "["|"]"|"++"|"--"|"auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"enum"|"extern"|"float"|"for"|"goto"|"inline"|"long"|"register"|"restrict"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"_Bool"|"_Complex"|"_Imaginary"
SIMPLECOMMENT   "//".*
MLCOMMENTS      "/*"
MLCOMMENTE      "*/"
%{
    #include<string.h>
    #include "y.tab.h"
    #include "structures.h"
    #include "print_lib.h"

    extern int syntax_error_counter;
    
    int lines = 1;
    int columns = 0;
    int verbose = 0;
    int sintaxTree = 0;
    int comment = 0;
    int linecomment = 0;
    int colcomment = 0;
    struct program* myprog;

    typedef enum {meta1, meta2} meta_flag;

    meta_flag mf;
%}

%x COMMENT CHARAC

%%

{CHAR}                                                      {if(verbose) printf("CHAR\n"); columns += yyleng; if(mf) return CHAR;}
{ELSE}                                                      {if(verbose) printf("ELSE\n"); columns += yyleng; if(mf) return ELSE;}
{WHILE}                                                     {if(verbose) printf("WHILE\n"); columns += yyleng; if(mf) return WHILE;}
{IF}                                                        {if(verbose) printf("IF\n"); columns += yyleng; if(mf) return IF;}
{INT}                                                       {if(verbose) printf("INT\n"); columns += yyleng; if(mf) return INT;}
{SHORT}                                                     {if(verbose) printf("SHORT\n");columns += yyleng; if(mf) return SHORT;}
{DOUBLE}                                                    {if(verbose) printf("DOUBLE\n");columns += yyleng; if(mf) return DOUBLE;}
{RETURN}                                                    {if(verbose) printf("RETURN\n");columns += yyleng; if(mf) return RETURN;}
{VOID}                                                      {if(verbose) printf("VOID\n");columns += yyleng; if(mf) return VOID;}
{BITWISEAND}                                                {if(verbose) printf("BITWISEAND\n");columns += yyleng; if(mf) return BITWISEAND;}
{BITWISEOR}                                                 {if(verbose) printf("BITWISEOR\n");columns += yyleng; if(mf) return BITWISEOR;}
{BITWISEXOR}                                                {if(verbose) printf("BITWISEXOR\n");columns += yyleng; if(mf) return BITWISEXOR;}
{AND}                                                       {if(verbose) printf("AND\n");columns += yyleng; if(mf) return AND;}
{ASSIGN}                                                    {if(verbose) printf("ASSIGN\n");columns += yyleng; if(mf) return ASSIGN;}
{MUL}                                                       {if(verbose) printf("MUL\n");columns += yyleng; if(mf) return MUL;}
{COMMA}                                                     {if(verbose) printf("COMMA\n");columns += yyleng; if(mf) return COMMA;}
{DIV}                                                       {if(verbose) printf("DIV\n");columns += yyleng; if(mf) return DIV;}
{EQ}                                                        {if(verbose) printf("EQ\n");columns += yyleng; if(mf) return EQ;}
{GE}                                                        {if(verbose) printf("GE\n");columns += yyleng; if(mf) return GE;}
{GT}                                                        {if(verbose) printf("GT\n");columns += yyleng; if(mf) return GT;}
{LBRACE}                                                    {if(verbose) printf("LBRACE\n");columns += yyleng; if(mf) return LBRACE;}
{LE}                                                        {if(verbose) printf("LE\n");columns += yyleng; if(mf) return LE;}
{LPAR}                                                      {if(verbose) printf("LPAR\n");columns += yyleng; if(mf) return LPAR;}
{LT}                                                        {if(verbose) printf("LT\n");columns += yyleng; if(mf) return LT;}
{MINUS}                                                     {if(verbose) printf("MINUS\n");columns += yyleng; if(mf) return MINUS;}
{MOD}                                                       {if(verbose) printf("MOD\n");columns += yyleng; if(mf) return MOD;}
{NE}                                                        {if(verbose) printf("NE\n");columns += yyleng; if(mf) return NE;}
{NOT}                                                       {if(verbose) printf("NOT\n");columns += yyleng; if(mf) return NOT;}
{OR}                                                        {if(verbose) printf("OR\n");columns += yyleng; if(mf) return OR;}
{PLUS}                                                      {if(verbose) printf("PLUS\n");columns += yyleng; if(mf) return PLUS;}
{RBRACE}                                                    {if(verbose) printf("RBRACE\n");columns += yyleng; if(mf) return RBRACE;}
{RPAR}                                                      {if(verbose) printf("RPAR\n");columns += yyleng; if(mf) return RPAR;}
{SEMI}                                                      {if(verbose) printf("SEMI\n");columns += yyleng; if(mf) return SEMI;}
{RESERVED}                                                  {if(verbose) printf("RESERVED(%s)\n",yytext);columns += yyleng; if(mf) return RESERVED;}
{ID}                                                        {if(verbose) printf("ID(%s)\n",yytext);columns += yyleng; yylval.string = (char*) strdup(yytext); if(mf) return ID;}
{INTLIT}                                                    {if(verbose) printf("INTLIT(%s)\n",yytext);columns += yyleng; yylval.integer = atoi(yytext); if(mf) return INTLIT;}
\'                                                          {BEGIN(CHARAC);columns++;}
<CHARAC>{CHRLIT}                                            {if(verbose) printf("CHRLIT('%s)\n",yytext);columns += yyleng;BEGIN(0); yylval.character = yytext[0]; if(mf) return CHRLIT;}
<CHARAC>((\\)?[^\'\n\\\r]|(\\\\)*(\\')?)*(\\)?(\n|\r|\r\n)  {printf("Line %d, col %d: unterminated char constant\n",lines,columns);++lines;columns = 0; BEGIN(0);}
<CHARAC>((\\)?[^\'\n\\\r]|(\\\\)*(\\')?)*(\\)?\'            {printf("Line %d, col %d: invalid char constant ('%s)\n",lines,columns, yytext);columns+=yyleng;BEGIN(0);}
<CHARAC>.                                                   {;}
<CHARAC><<EOF>>                                             {printf("Line %d, col %d: unterminated char constant\n",lines,columns);++lines;columns = 0; BEGIN(0);}
{REALLIT}                                                   {if(verbose) printf("REALLIT(%s)\n",yytext);columns += yyleng; yylval.dfloat = atof(yytext); if(mf) return REALLIT;}
{SIMPLECOMMENT}                                             {;if(mf) return SIMPLECOMMENT;}  
{MLCOMMENTS}                                                {BEGIN(COMMENT);columns += yyleng; comment = 1;linecomment = lines;colcomment = columns - 1; if(mf) return MLCOMMENTS;}
<COMMENT>{MLCOMMENTE}                                       {comment = 0;columns += yyleng; BEGIN 0; if(mf) return MLCOMMENTE;}
<COMMENT>.                                                  {;columns += yyleng;}
<COMMENT>\n|\r|\r\n	                                        {++lines;columns = 0;}
[\t ]                                                       {columns += yyleng;}
\n|\r|\r\n                                                  {++lines; columns = 0;}
.                                                           {columns++;printf("Line %d, col %d: illegal character (%s)\n", lines, columns, yytext);}

%%

int main(int argc, char* argv[]) {
    /* [Se nenhuma flag for passada] : */ 
    mf = meta2; //isto é supostor ir atualizando para ficar sempre a ultima meta por default
    for(int i = 1; i < argc; i++){
        if(strcmp("-l", argv[i]) == 0){
            verbose = 1;
            mf = meta1;	// Enunciado diz que se for passada -l faz apenas o lexer	
        }
        else if(strcmp("-t", argv[i]) == 0){
            sintaxTree = 1;	
        }
        else if(strcmp("-e1", argv[i]) == 0){
            mf = meta1;	
        }
        else if(strcmp("-e2", argv[i]) == 0){
            mf = meta2;
        }
    }
    switch(mf){
        case meta1:
            yylex();
            break;
        case meta2:
            yyparse();
            print_ast(myprog);
            break;
    }
    
    if(comment)
        printf("Line %d, col %d: unterminated comment\n", linecomment, colcomment);
    return 0;
}

int yywrap() {
    if(sintaxTree && syntax_error_counter == 0){
        /*fazer aqui print_ast()*/
       /*  printf("        Arvore dos deuses\n");
        printf("            /       \\\n");
        printf("           /         \\\n");
        printf("        LEFT         RIGHT\n");
        printf("        /  \\        /    \\\n");
        printf("       /    \\      /      \\\n");
        printf("     LEFT  RIGHT LEFT    RIGHT\n"); */
        //print_ast(myprog);
    }
    return 1;
}


