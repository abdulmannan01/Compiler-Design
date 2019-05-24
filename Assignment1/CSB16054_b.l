%{
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("\n %s : PREPROCESSOR DIRECTIVE",yytext);}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {printf("\n %s : KEYWORD",yytext);}
"/*" {COMMENT=1;}{printf("\n\t %s : COMMENT",yytext);}
{identifier}\( {if(!COMMENT)printf("\n FUNCTION\n %s",yytext);}
\{  {if(!COMMENT)printf("\n BLOCK BEGINS");}
\}  {if(!COMMENT)printf("\n BLOCK ENDS ");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n %s : IDENTIFIER",yytext);}
\".*\" {if(!COMMENT)printf("\n %s : STRING",yytext);}
[0-9]+ {if(!COMMENT) printf("\n %s : NUMBER ",yytext);}
\)(\:)? {if(!COMMENT)ECHO;}
\( ECHO;
\; {if(!COMMENT)printf("\n %s : TERMINATOR",yytext);}
\, {if(!COMMENT)printf("\n %s : OPERATOR",yytext);}
\+ |
\* |
\/ |
\- {if(!COMMENT)printf("\n %s : ARITHMETIC OPERATOR", yytext);}
= {if(!COMMENT)printf("\n %s : ASSIGNMENT OPERATOR",yytext);}
\<= |
\>= |
\< |
== |
\> {if(!COMMENT) printf("\n %s : RELATIONAL OPERATOR",yytext);}
%%
int main(int argc, char **argv)
{
FILE *file;
file=fopen("inputb.c","r");
if(!file)
{
printf("could not open the file");
exit(0);
}
yyin=file;
yylex();
return(0);
}
int yywrap()
{
return(1);
}
