#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

double ParseWhile();        // for while loop
double ParseCondition();    // for condition of while loop
double ParseBegin();        // for begin of statement
double ParseEnd();          // for end of statement
double ParseNumber();       // for multi-digit and decimal number
double ParseSum();          // for summation statement
double ParseProduct();      // for multiplication statement
double ParseFactor();       // for finding factors for multiplication and adding
double ParseFormula();      // for end of the entire construct

#define size 100

char x[size];
int count=0;

int main()
{
	printf("Enter the Construct: e.g. W(a==5)B(2*3)+200+20*10+(2+1)E \t");	//W(a==5)B(2*3)+200+20*10+(2+1)E
	scanf("%s", x);
	
	double result = ParseWhile();	//calling the parse function

	printf("Result: %f",result);	

	return 0;
}

double ParseWhile()
{
	if(x[count] == 'W')
	{
		count++;
		return ParseWhile();
	}
	else if(x[count] == '(')
	{
	    count++;
	    double equ = ParseCondition();
	    count++; 
		return ParseFormula();
	}
	else
	   printf("error:While Loop");
}
double ParseCondition()
{
	if(x[count] == 'a')
	{
	    count++;
        return ParseCondition();
	}
	else if(x[count] == '=')
	{
		count++;
		return ParseCondition();
	}
	else if(x[count] == '=')
	{
	    count++;
		return ParseCondition();
	}
	else if(isdigit(x[count]))
	{
        count++;
        return 0;
    }
    else
        printf("error:Condition");

}

double ParseBegin()
{
	if(x[count] == 'B')
	{
		count++;
		return ParseFactor();
	}
}

double ParseEnd()
{
	double result = ParseSum();

	if(x[count]=='E')
	{
		count++;
		return result;
	}
	printf("expected end but found %c\n",x[count]);

}
double ParseFormula()
{
    double result= ParseEnd();

	if(x[count]=='\0')
	{
		return result;
	}
	printf("expected end of input but found %c\n",x[count]);

}
double ParseNumber()
{
	double number = 0;

	while(x[count] >= '0' && x[count] <= '9')
	{
		number = number*10;
		number = number+(x[count]-'0');
		count++;
	}

	if(x[count] == '.')
	{
		count++; 
		double weight = 1;

        while(x[count] >= '0'&& x[count] <= '9')
        {
            weight = weight/10;
            double scaled = (x[count]-'0')*weight;
            number = number+scaled;
            count++;
        }
	}
	return number;
}
double ParseFactor()
{
	if(x[count] >= '0'&& x[count] <= '9')
	{
		return ParseNumber();
	}
	else if(x[count] == '(')
	{
		count++;
		double sum = ParseSum();
	        count++;
		return sum;
	}
	else if(x[count] == 'B')
	{
		return ParseBegin();
	}
	else
	{
		printf("expected digit but found %c\n",*x);
	}
}

double ParseProduct()
{

	double left = ParseFactor();
	while(x[count] == '*')
	{
		count++;
		double right = ParseFactor();
		left = left*right;
	}
	return left;
}

double ParseSum()
{
	double left = ParseProduct();
	while(x[count] == '+')
	{
		count++;
		double right = ParseProduct();
		left = left+right;
	}
	return left;
}

