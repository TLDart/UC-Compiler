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
BITWISEXOR      "ˆ"
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
ID              [a-zA-Z_]+
INTLIT          [0-9]+
CHRLIT          \'(\\n|\\t|\\\\|\\'|\\\"|\\[0-7][0-7]?[0-7]?|[^\n\'])\'
REALLIT         ([0-9]+"."[0-9]*((e|E)[+-][0-9]+)?)|("."[0-9]+((e|E)[+-][0-9]+)?)|([0-9]+((e|E)[+-][0-9]+))
RESERVED        "["|"]"|"++"|"--"
%{
    #include<string.h>
    int lines = 1;
    int columns = 1;
    int verbose = 0;
%}
%%
{CHAR}           {if(verbose) printf("CHAR\n"); columns += sizeof(yylex);}
{ELSE}           {if(verbose) printf("ELSE\n"); columns += sizeof(yylex);}
{WHILE}          {if(verbose) printf("WHILE\n"); columns += sizeof(yylex);}
{IF}             {if(verbose) printf("IF\n"); columns += sizeof(yylex);}
{INT}            {if(verbose) printf("INT\n"); columns += sizeof(yylex);}
{SHORT}          {if(verbose) printf("SHORT\n");columns += sizeof(yylex);}
{DOUBLE}         {if(verbose) printf("DOUBLE\n");columns += sizeof(yylex);}
{RETURN}         {if(verbose) printf("RETURN\n");columns += sizeof(yylex);}
{VOID}           {if(verbose) printf("VOID\n");columns += sizeof(yylex);}
{BITWISEAND}     {if(verbose) printf("BITWISEAND\n");columns += sizeof(yylex);}
{BITWISEOR}      {if(verbose) printf("BITWISEOR\n");columns += sizeof(yylex);}
{BITWISEXOR}     {if(verbose) printf("BITWISEXOR\n");columns += sizeof(yylex);}
{AND}            {if(verbose) printf("AND\n");columns += sizeof(yylex);}
{ASSIGN}         {if(verbose) printf("ASSIGN\n");columns += sizeof(yylex);}
{MUL}            {if(verbose) printf("MUL\n");columns += sizeof(yylex);}
{COMMA}          {if(verbose) printf("COMMA\n");columns += sizeof(yylex);}
{DIV}            {if(verbose) printf("DIV\n");columns += sizeof(yylex);}
{EQ}             {if(verbose) printf("EQ\n");columns += sizeof(yylex);}
{GE}             {if(verbose) printf("GE\n");columns += sizeof(yylex);}
{GT}             {if(verbose) printf("GT\n");columns += sizeof(yylex);}
{LBRACE}         {if(verbose) printf("LBRACE\n");columns += sizeof(yylex);}
{LE}             {if(verbose) printf("LE\n");columns += sizeof(yylex);}
{LPAR}           {if(verbose) printf("LPAR\n");columns += sizeof(yylex);}
{LT}             {if(verbose) printf("LT\n");columns += sizeof(yylex);}
{MINUS}          {if(verbose) printf("MINUS\n");columns += sizeof(yylex);}
{MOD}            {if(verbose) printf("MOD\n");columns += sizeof(yylex);}
{NE}             {if(verbose) printf("NE\n");columns += sizeof(yylex);}
{NOT}            {if(verbose) printf("NOT\n");columns += sizeof(yylex);}
{OR}             {if(verbose) printf("OR\n");columns += sizeof(yylex);}
{PLUS}           {if(verbose) printf("PLUS\n");columns += sizeof(yylex);}
{RBRACE}         {if(verbose) printf("RBRACE\n");columns += sizeof(yylex);}
{RPAR}           {if(verbose) printf("RPAR\n");columns += sizeof(yylex);}
{SEMI}           {if(verbose) printf("SEMI\n");columns += sizeof(yylex);}
{ID}             {if(verbose) printf("ID(%s)\n",yytext);columns += sizeof(yylex);}
{INTLIT}         {if(verbose) printf("INTLIT(%s)\n",yytext);columns += sizeof(yylex);}
{CHRLIT}         {if(verbose) printf("CHRLIT(%s)\n",yytext);columns += sizeof(yylex);}
{REALLIT}        {if(verbose) printf("REALLIT(%s)\n",yytext);columns += sizeof(yylex);}
{RESERVED}       {if(verbose) printf("RESERVED(%s)\n",yytext);columns += sizeof(yylex);}
[\t ]            {columns += sizeof(yylex);}
\n               {++lines; columns = 1;}
.                {printf("ERRO!");}
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
    return 0;
}

int yywrap() {
    return 1;
}
