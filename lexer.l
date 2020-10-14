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
SIMPLECOMMENT "//".*
MLCOMMENTS "/*"
MLCOMMENTE "*/"
%{
    #include<string.h>
    int lines = 1;
    int columns = 0;
    int verbose = 0;
    int comment = 0;
    int linecomment = 0;
    int colcomment = 0;
%}
%X COMMENT CHARAC
%%
{CHAR}                              {if(verbose) printf("CHAR\n"); columns += yyleng;}
{ELSE}                              {if(verbose) printf("ELSE\n"); columns += yyleng;}
{WHILE}                             {if(verbose) printf("WHILE\n"); columns += yyleng;}
{IF}                                {if(verbose) printf("IF\n"); columns += yyleng;}
{INT}                               {if(verbose) printf("INT\n"); columns += yyleng;}
{SHORT}                             {if(verbose) printf("SHORT\n");columns += yyleng;}
{DOUBLE}                            {if(verbose) printf("DOUBLE\n");columns += yyleng;}
{RETURN}                            {if(verbose) printf("RETURN\n");columns += yyleng;}
{VOID}                              {if(verbose) printf("VOID\n");columns += yyleng;}
{BITWISEAND}                        {if(verbose) printf("BITWISEAND\n");columns += yyleng;}
{BITWISEOR}                         {if(verbose) printf("BITWISEOR\n");columns += yyleng;}
{BITWISEXOR}                        {if(verbose) printf("BITWISEXOR\n");columns += yyleng;}
{AND}                               {if(verbose) printf("AND\n");columns += yyleng;}
{ASSIGN}                            {if(verbose) printf("ASSIGN\n");columns += yyleng;}
{MUL}                               {if(verbose) printf("MUL\n");columns += yyleng;}
{COMMA}                             {if(verbose) printf("COMMA\n");columns += yyleng;}
{DIV}                               {if(verbose) printf("DIV\n");columns += yyleng;}
{EQ}                                {if(verbose) printf("EQ\n");columns += yyleng;}
{GE}                                {if(verbose) printf("GE\n");columns += yyleng;}
{GT}                                {if(verbose) printf("GT\n");columns += yyleng;}
{LBRACE}                            {if(verbose) printf("LBRACE\n");columns += yyleng;}
{LE}                                {if(verbose) printf("LE\n");columns += yyleng;}
{LPAR}                              {if(verbose) printf("LPAR\n");columns += yyleng;}
{LT}                                {if(verbose) printf("LT\n");columns += yyleng;}
{MINUS}                             {if(verbose) printf("MINUS\n");columns += yyleng;}
{MOD}                               {if(verbose) printf("MOD\n");columns += yyleng;}
{NE}                                {if(verbose) printf("NE\n");columns += yyleng;}
{NOT}                               {if(verbose) printf("NOT\n");columns += yyleng;}
{OR}                                {if(verbose) printf("OR\n");columns += yyleng;}
{PLUS}                              {if(verbose) printf("PLUS\n");columns += yyleng;}
{RBRACE}                            {if(verbose) printf("RBRACE\n");columns += yyleng;}
{RPAR}                              {if(verbose) printf("RPAR\n");columns += yyleng;}
{SEMI}                              {if(verbose) printf("SEMI\n");columns += yyleng;}
{RESERVED}                          {if(verbose) printf("RESERVED(%s)\n",yytext);columns += yyleng;}
{ID}                                {if(verbose) printf("ID(%s)\n",yytext);columns += yyleng;}
{INTLIT}                            {if(verbose) printf("INTLIT(%s)\n",yytext);columns += yyleng;}
\'                                  {BEGIN(CHARAC);columns++;}
<CHARAC>{CHRLIT}                    {if(verbose) printf("CHRLIT('%s)\n",yytext);columns += yyleng;BEGIN(0);}
<CHARAC>(\\|(([^\n\r\'\\]|\\'|\\\\|\\[^\\\n\r])*)(\n|\r|\r\n))       {printf("Line %d, col %d: unterminated char constant\n",lines,columns);++lines;columns = 0; BEGIN(0);}
<CHARAC>([^\'\n\r]|\\')*\'                  {printf("Line %d, col %d: invalid char constant ('%s)\n",lines,columns, yytext);columns+=yyleng;BEGIN(0);}
{REALLIT}                           {if(verbose) printf("REALLIT(%s)\n",yytext);columns += yyleng;}
{SIMPLECOMMENT}                     {;}  
{MLCOMMENTS}                        {BEGIN(COMMENT);columns += yyleng; comment = 1;linecomment = lines;colcomment = columns - 1;}
<COMMENT>{MLCOMMENTE}               {comment = 0;columns += yyleng; BEGIN 0;}
<COMMENT>.                          {;columns += yyleng;}
<COMMENT>\n|\r|\r\n	                        {++lines;columns = 0;}
[\t ]                               {columns += yyleng;}
\n|\r|\r\n                                  {++lines; columns = 0;}
.                                   {columns++;printf("Line %d, col %d: illegal character (%s)\n", lines, columns, yytext);}
%%
int main(int argc, char* argv[]) {
   for(int i = 0; i < argc; i++){
	if(strcmp("-l", argv[i]) == 0){
		verbose = 1;	
	}
	else if(strcmp("-e1", argv[i]) == 0){
		verbose = 0;	
	}
   }	
    yylex();
    if(comment)
        printf("Line %d, col %d: unterminated comment\n", linecomment, colcomment);
    return 0;
}

int yywrap() {
    return 1;
}
