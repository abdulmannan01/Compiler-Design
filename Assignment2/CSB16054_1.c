#include <stdio.h>
#include <math.h>
#include <limits.h>

double calculate(char , double , double );
char checknumber(char);
double evaluate (char []);
int precedence  (char);

double calculate(char moperator, double num1, double num2) 
{   
    double result;
    switch (moperator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        printf("Invalid Operator\n");
        exit(-1);
    }
    return result;
}


char checknumber(char ch) 
{
    if ((ch >= '0' && ch <= '9') || ch == '.') 
	return 1; 
	else return 0;
}


double evaluate(char expr[])
{
    double number[5]; 
	int ni = 0;
    char Operator[5]; 
	int oi = 0;
    char numbuffer[16];   
	int bi = 0;
    char ch; 
	int i = 0;

    while ((ch = expr[i]) != 0) {
        if (checknumber(ch)) 
        {
            numbuffer[bi++] = ch;
            if (!checknumber(expr[i + 1])) 
            {
                numbuffer[bi] = 0; 
				bi = 0;
                sscanf(numbuffer, "%lf", &number[ni++]); 
            }
        }
        else
        {
            while ((oi > 0) && (precedence(ch) <= precedence(Operator[oi - 1])))
            {
                number[ni - 2] = calculate(Operator[oi - 1], number[ni - 2], number[ni - 1]);
                oi--; ni--;
            }
            Operator[oi++] = ch;          
        }
        i++;
    }
    while (oi > 0) {
        number[ni - 2] = calculate(Operator[oi - 1], number[ni - 2], number[ni - 1]);
        oi--; ni--;
    }
    return number[0];
}

int precedence(char ch)
{
    switch (ch) 
    {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
        return 1;
    case '^':
        return 2;
    }
    return INT_MAX;
}

int main(void)
{
    char expression[100];
    double result;
    printf("Enter the Expression: ");
	scanf("%[^\n]", expression);
    result = evaluate(expression);
    printf("Result = %lf\n", result);
    return 0;
}