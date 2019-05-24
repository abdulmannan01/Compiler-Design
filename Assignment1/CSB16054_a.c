#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "token.h"

void readfile(FILE *fp)
{
    char yytext[100];
    int i = 0;
    char ch;
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (isalpha(ch))
        {
            while (isalpha(ch) || isdigit(ch))
            {

                yytext[i] = ch;
                i++;
                ch = fgetc(fp);
            }

            yytext[i] = '\0';
            recognizetoken(yytext);
            i = 0;
            yytext[0] = '\0';
        }
        
        else if (isdigit(ch))
        {
            while (isdigit(ch))
            {

                yytext[i] = ch;
                i++;
                ch = fgetc(fp);
            }

            yytext[i] = '\0';
            recognizetoken(yytext);
            i = 0;
            yytext[0] = '\0';
        }
        
        else if (ch == '+' || ch == '=' )
        {
            while (!isspace(ch))
            {

                yytext[i] = ch;
                i++;
                ch = fgetc(fp);
            }

            yytext[i] = '\0';
            recognizetoken(yytext);
            i = 0;
            yytext[0] = '\0';
        }
    }

}
void recognizetoken(char str[]){

    if(!strcmp(str,"int")){
        printf("%s : KEYWORD with TOKEN ID : %d\n", str,TOK_INT);
        return;
    }
    
    else if(!strcmp(str,"return")){
        printf("%s : KEYWORD with TOKEN ID : %d\n", str,TOK_RETURN);
        return;
    }
    
    else if(!strcmp(str,"main")){
        printf("%s : KEYWORD with TOKEN ID : %d\n", str,TOK_MAIN);
        return;
    }

    else if(!strcmp(str,"printf")){
        printf("%s : KEYWORD with TOKEN ID : %d\n", str,TOK_PRINTF);
        return;
    }

    else if(isdigit(str[0])){
        printf("%s : NUMBER \n", str);
        return;
    }

    else if(str[0] == '+' || str[0] == '='  ){
        printf("%s : ARITHMETIC OPERATOR \n", str);
        return;
    }

    else{
        
        printf("%s : IDENTIFIER with TOKEN ID :  %d\n", str,TOK_ID);
        return;
    }

}
int main()
{

    FILE *fp = fopen("inputa.c", "r");
    if (fp == NULL)
    {
        printf("Error in opening file. \n");
    }
    else
    {

        printf("File opened successfully. \n\n");
        readfile(fp);
    }
}
