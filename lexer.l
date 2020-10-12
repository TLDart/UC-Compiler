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
    int lines = 1;
    int columns = 1;
%}
%%
{CHAR}           {printf("CHAR\n"); columns += sizeof(yylex);}
{ELSE}           {printf("ELSE\n"); columns += sizeof(yylex);}
{WHILE}          {printf("WHILE\n"); columns += sizeof(yylex);}
{IF}             {printf("IF\n"); columns += sizeof(yylex);}
{INT}            {printf("INT\n"); columns += sizeof(yylex);}
{SHORT}          {printf("SHORT\n");columns += sizeof(yylex);}
{DOUBLE}         {printf("DOUBLE\n");columns += sizeof(yylex);}
{RETURN}         {printf("RETURN\n");columns += sizeof(yylex);}
{VOID}           {printf("VOID\n");columns += sizeof(yylex);}
{BITWISEAND}     {printf("BITWISEAND\n");columns += sizeof(yylex);}
{BITWISEOR}      {printf("BITWISEOR\n");columns += sizeof(yylex);}
{BITWISEXOR}     {printf("BITWISEXOR\n");columns += sizeof(yylex);}
{AND}            {printf("AND\n");columns += sizeof(yylex);}
{ASSIGN}         {printf("ASSIGN\n");columns += sizeof(yylex);}
{MUL}            {printf("MUL\n");columns += sizeof(yylex);}
{COMMA}          {printf("COMMA\n");columns += sizeof(yylex);}
{DIV}            {printf("DIV\n");columns += sizeof(yylex);}
{EQ}             {printf("EQ\n");columns += sizeof(yylex);}
{GE}             {printf("GE\n");columns += sizeof(yylex);}
{GT}             {printf("GT\n");columns += sizeof(yylex);}
{LBRACE}         {printf("LBRACE\n");columns += sizeof(yylex);}
{LE}             {printf("LE\n");columns += sizeof(yylex);}
{LPAR}           {printf("LPAR\n");columns += sizeof(yylex);}
{LT}             {printf("LT\n");columns += sizeof(yylex);}
{MINUS}          {printf("MINUS\n");columns += sizeof(yylex);}
{MOD}            {printf("MOD\n");columns += sizeof(yylex);}
{NE}             {printf("NE\n");columns += sizeof(yylex);}
{NOT}            {printf("NOT\n");columns += sizeof(yylex);}
{OR}             {printf("OR\n");columns += sizeof(yylex);}
{PLUS}           {printf("PLUS\n");columns += sizeof(yylex);}
{RBRACE}         {printf("RBRACE\n");columns += sizeof(yylex);}
{RPAR}           {printf("RPAR\n");columns += sizeof(yylex);}
{SEMI}           {printf("SEMI\n");columns += sizeof(yylex);}
{ID}             {printf("ID(%s)\n",yytext);columns += sizeof(yylex);}
{INTLIT}         {printf("INTLIT(%s)\n",yytext);columns += sizeof(yylex);}
{CHRLIT}         {printf("CHRLIT(%s)\n",yytext);columns += sizeof(yylex);}
{REALLIT}        {printf("REALLIT(%s)\n",yytext);columns += sizeof(yylex);}
{RESERVED}       {printf("RESERVED(%s)\n",yytext);columns += sizeof(yylex);}
[\t ]            {columns += sizeof(yylex);}
\n               {++lines; columns = 1;}
.                {printf("ERRO!");}
%%
int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
