#include<stdio.h>
#include<stdlib.h>

void field_no(FILE *fp, int num)
{
    char ch;
    int i = 0;

    while((ch = fgetc(fp)) != EOF)
    {
        if(i == num-1 && ch != ' ')
            putchar(ch);

        else if(ch == ' ')
            i++;

        else if(ch == '\n')
        {
            i = 0;

            printf("\n");
        }
    }
}

int main()
{
    FILE *fp;
    int num;

    fp = fopen("input.txt", "r");

    if(fp == NULL)
    {
        printf("Can't open file.");
        exit(0);
    }
    else
    {
        printf("\nEnter the field number: ");
        scanf("%d", &num);

        printf("\n");

        field_no(fp, num);
    }
}
