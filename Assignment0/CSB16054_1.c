#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

void fgets_print(FILE *fp)
{
        char str[MAX];
        int i = 0;

        while(fgets(str, MAX, fp) != NULL)
                printf("\n%d. %s", ++i, str);
        printf("\n");

}

void fgetc_print(FILE *fp)
{
        char c;
        int i = 1;

        printf("1. ");
        while(!feof(fp))
        {
                c = fgetc(fp);

                if(c == '\n')
                {
                        printf("%c", c);

                        printf("\n%d. ", ++i);

                        continue;
                }

                printf("%c", c);
        }
        printf("\n");

}

int main()
{
        FILE *fp;
        int choice, i;
        char str[MAX], c;

        fp = fopen("input.txt", "r");

        if(fp == NULL)
        {
                printf("Can't open file.");
                exit(0);
        }

        else
        {
                printf("\nPrint using fgets or fgetc? \n1. fgets()\n2. fgetc()\n");
                scanf("%d", &choice);

                switch(choice)
                {
                        case 1:
                                fgets_print(fp);
                                break;

                        case 2:

                               fgetc_print(fp);
                                break;

                        default:
                                printf("\nWrong choice!");
                                exit(0);
                                break;
                }
        }
        return 0;
}