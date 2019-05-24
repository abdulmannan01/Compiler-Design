#include<stdio.h>
#include<stdlib.h>

int main()
{
        FILE *fp;
        int num;
        char ch, choice;

        fp = fopen("Student_record.bin", "rb");

        if(fp == NULL)
        {
                printf("Can't open file.");
                exit(0);
        }
        else
        {
                printf("\nEnter b for reading in octal and c for reading in character format: ");
                scanf("%c", &choice);

                switch(choice)
                {
                case 'b':
                        while((ch = fgetc(fp)) != EOF)
                                printf("%o ", ch);
                        break;

                case 'c':
                        while((ch = fgetc(fp)) != EOF)
                                printf("%c ", ch);
                        break;

                default:
                        printf("Wrong option.");
                }
        }

        fclose(fp);

        return 0;
}