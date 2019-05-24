#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int noT;

typedef struct rule
{
	char lhs;
	char rhs[10];
	int num;
}rule;

struct rule rules[15];

typedef struct lead
{
	char c;
	char set[10];
	int len;
}lead;

struct lead leads[10];

typedef struct trail
{
	char c;
	char set[10];
	int len;
}trail;

struct trail trails[10];

int isNonTerminal(char c,int noRules)
{	
	int i=0;
	for(i;i<noRules;i++)
		if(rules[i].lhs==c)
		return 1;
	return 0;
}

int inarr(char* arr,char c,int noRules)
{
	int i;
	for(i=0;i<noRules;i++)
		if(arr[i]==c)
			return 1;
	return 0;
}

int isInLS(char NT, char ch,int noNT)
{
	int i=0;
	int j=0;
	for(i=0;i<noNT;i++)
		if(leads[i].c==NT)
			break;
	for(j=0;j<=leads[i].len;j++)		
		if(leads[i].set[j]==ch)
			return 1;
	
	return 0;
}

int isInTS(char NT, char ch,int noNT)
{
	int i=0;
	int j=0;
	for(i=0;i<noNT;i++)
		if(trails[i].c==NT)
			break;
	for(j=0;j<=trails[i].len;j++)		
		if(trails[i].set[j]==ch)
			return 1;
	
	return 0;
}

void copylead(char NT1,char NT2,int noNT)
{
	//printf("\n");
	int i,j;
	char ch;
	for(i=0;i<noNT;i++)
		if(leads[i].c==NT1)
			break;
	for(j=0;j<noNT;j++)
		if(leads[j].c==NT2)
			break;

	int ind;
	int k;
	for(k=0;k<leads[j].len;k++)
	{
		ind = leads[i].len;
		ch = leads[j].set[k];
		if(!isInLS(NT1,ch,noNT))
		{
			leads[i].set[ind]=ch;
			leads[i].len++;
		}		
	}

}

void copytrail(char NT1,char NT2,int noNT)
{
	//printf("\n");
	int i,j;
	char ch;
	for(i=0;i<noNT;i++)
		if(trails[i].c==NT1)
		break;
	for(j=0;j<noNT;j++)
		if(trails[j].c==NT2)
			break;
	int ind;
	int k;
	for(k=0;k<trails[j].len;k++)
	{
		ind = trails[i].len;
		ch = trails[j].set[k];
		if(!isInTS(NT1,ch,noNT))
		{
			trails[i].set[ind]=ch;
			trails[i].len++;
		}		
	}

}

void add2leading(char NT1,char NT2,int noRules,int noNT)
{
	int i=0;
	char first=0;
	char second=0;
	for(i=0;i<noRules;i++)
	{
		if(rules[i].lhs==NT2)
		{
			first=rules[i].rhs[0];
			if(isNonTerminal(first,noRules))
			{
				add2leading(NT2,first,noRules,noNT);
				copylead(NT1,NT2,noNT);
			}
			else  if(!isNonTerminal(first,noRules))
				copylead(NT1,NT2,noNT);
		}	
	}
}

void add2trailing(char NT1,char NT2,int noRules,int noNT)
{
	int i=0;
	char last=0;
	char seclast=0;
	for(i=0;i<noRules;i++)
	{
		if(rules[i].lhs==NT2)
		{
			int index;
			index = rules[i].num;
			last=rules[i].rhs[index];
			if(isNonTerminal(last,noRules))
			{
				add2trailing(NT2,last,noRules,noNT);
				copytrail(NT1,NT2,noNT);
			}
			else  if(!isNonTerminal(last,noRules))
			{
				copytrail(NT1,NT2,noNT);
			}
		}	
	}
}

int charIndex(char c,char* term,int noT)
{
	int i;
	if(c=='\0')
		return -1;
	for(i=0;i<noT;i++)
	{
		if(c==term[i])
			return i;
	}
}

void printOPT(char OPT[noT][noT],char* term)
{
	printf("OPERATOR PRECEDENCE TABLE :\n\n");
	printf("X denotes ERROR\n");
	printf("< denotes YIELDS PRECEDENCE TO\n");
	printf("> denotes TAKES PRECEDENCE OVER\n");
	printf("= denotes HAS SAME PRECEDENCE AS\n\n");
	int i,j;
	for(i=0;i<noT;i++)
		printf("\t%c",term[i]);
	printf("\n");
	for(i=0;i<noT;i++)
	{
		printf("%c\t",term[i]);
		for(j=0;j<noT;j++)
			printf("%c\t",OPT[i][j]);
		printf("\n");
	}
}

int main()
{
	rules[0].lhs = 'S';
	strncpy(rules[0].rhs,"w(C)bAe",7);
	rules[0].num = 6;
	rules[1].lhs = 'C';
	strncpy(rules[1].rhs,"iOi",3);
	rules[1].num = 2;
	rules[2].lhs = 'C';
	strncpy(rules[2].rhs,"iOn",3);
	rules[2].num = 2;
	rules[3].lhs = 'O';
	strncpy(rules[3].rhs,"p",1);
	rules[3].num = 0;
	rules[4].lhs = 'A';
	strncpy(rules[4].rhs,"L;A",3);
	rules[4].num = 2;
	rules[5].lhs = 'A';
	strncpy(rules[5].rhs,"f",1);
	rules[5].num = 0;
	rules[6].lhs = 'L';
	strncpy(rules[6].rhs,"i=E",3);
	rules[6].num = 2;
	rules[7].lhs = 'E';
	strncpy(rules[7].rhs,"T*F",3);
	rules[7].num = 2;
	rules[8].lhs = 'T';
	strncpy(rules[8].rhs,"i",1);
	rules[8].num = 0;
	rules[9].lhs = 'F';
	strncpy(rules[9].rhs,"n",1);
	rules[9].num = 0;

	int i,j;
	int noRules=10;
	char NT,NT1,NT2;
	printf("\nRULES :\n");
	for(i=0;i<noRules;i++)
	{
		printf("%c\t-->\t",rules[i].lhs);
		for(j=0;j<(rules[i].num)+1;j++)
			printf("%c",rules[i].rhs[j]);
		printf("\t%d\n",rules[i].num);
	}
	char arr[noRules];
	char ch;
	int k=0;
	for(i=0;i<noRules;)
	{
		ch = rules[i].lhs;
		if(!inarr(arr,ch,noRules))
			arr[k++]=ch;
		else if(inarr(arr,ch,noRules))
			i++;
	}
	printf("\n\nNON TERMINALS ARE :\n");
	for(i=0;i<k;i++)
	{
		leads[i].c=arr[i];
		trails[i].c=arr[i];
		printf("%c\n",leads[i].c);
	}
	int noNT,index;
	noNT = k;
	
	//leading set calculation
	for(i=0;i<noRules;i++)
	{
		char first=0;
		char second=0;
		first = rules[i].rhs[0];
		if(rules[i].num!=0)
			second = rules[i].rhs[1];
		if(!isNonTerminal(first,noRules))
		{
			NT = rules[i].lhs;			
			for(j=0;j<noNT;j++)
				if(leads[j].c==NT)
				break;
			if(!isInLS(NT,first,noNT))			
			{
				index = leads[j].len;
				leads[j].set[index]=first;
				leads[j].len++;
			}			
		}
		else if(isNonTerminal(first,noRules))
		{
			if((!isNonTerminal(second,noRules))&&(rules[i].num!=0))
			{
				NT = rules[i].lhs;
				for(j=0;j<noNT;j++)
					if(leads[j].c==NT)
					break;
				if(!isInLS(NT,second,noNT))
				{
					index = leads[j].len;
					leads[j].set[index]=second;
					leads[j].len++;
				}
			}
			
		}
	}
	for(i=0;i<noRules;i++)
	{
		char first=0;		
		first = rules[i].rhs[0];
		if(isNonTerminal(first,noRules))
		{
			NT1 = rules[i].lhs;
			NT2 = rules[i].rhs[0];
			printf("\n");
			add2leading(NT1,NT2,noRules,noNT);
		}
	}
	printf("LEADING SET OF :\n");
	for(i=0;i<noNT;i++)
	{
		printf("%c\tlength = %d\t%s\n",leads[i].c,leads[i].len,leads[i].set);
	}	
	
	//trailing set calculation
	for(i=0;i<noRules;i++)
	{
		char last=0;
		char seclast=0;		
		index = rules[i].num;
		last = rules[i].rhs[index];
		if(index!=0)
			seclast = rules[i].rhs[index-1];
		if(!isNonTerminal(last,noRules))
		{
			NT = rules[i].lhs;
			for(j=0;j<noNT;j++)
				if(trails[j].c==NT)
				break;
			if(!isInTS(NT,last,noNT))
			{
				index = trails[j].len;
				trails[j].set[index]=last;
				trails[j].len++;
			}
		}
		else if(isNonTerminal(last,noRules))
		{
			if((!isNonTerminal(seclast,noRules))&&(rules[i].num!=0))
			{
				NT = rules[i].lhs;
				for(j=0;j<noNT;j++)
					if(trails[j].c==NT)
					break;
				if(!isInTS(NT,seclast,noNT))
				{
					index = trails[j].len;
					trails[j].set[index]=seclast;
					trails[j].len++;
				}
			}
			
		}
	}
	
	for(i=0;i<noRules;i++)
	{
		char last=0;
		index = rules[i].num;
		last = rules[i].rhs[index];		
		if(isNonTerminal(last,noRules))
		{
			NT1 = rules[i].lhs;
			NT2 = last;
			printf("\n");
			if(NT1!=NT2)
				add2trailing(NT1,NT2,noRules,noNT);
		}
	}
	printf("TRAILING SET OF :\n");
	for(i=0;i<noNT;i++)
	{
		printf("%c\tlength = %d\t%s\n",trails[i].c,trails[i].len,trails[i].set);
	}	
	
	printf("\n\n");
	k=0;
	char term[40];
	for(i=0;i<noRules;i++)
	{
		int len;
		len = rules[i].num+1;
		for(j=0;j<=len;j++)
		{
			ch = rules[i].rhs[j];
			if(!isNonTerminal(ch,noRules))
			{
				if((!inarr(term,ch,noRules))&&ch!='\0')
				{		
					term[k++]=ch;
					//printf("%c",ch);
				}
			}
		}
		
	}
	term[k++]='$';
	noT = k;		
	printf("TERMINALS ARE :\n");
	for(i=0;i<noT-1;i++)
		printf("%c\n",term[i]);
	
    //initialising precedence table
	char OPT[noT][noT];
	for(i=0;i<noT;i++)
		for(j=0;j<noT;j++)
			OPT[i][j]='X';
	
    //creating OPT from leading/trailing sets...
	char startNT;
	startNT = leads[0].c;
	printf("\nSTART SYMBOL = %c\n\nCREATING TABLE FROM LEADING AND TRAILING SETS :\n\n",startNT);
	
    //$<leading(S) and trailing(S)>$
	for(i=0;i<leads[0].len;i++)
	{
		char s,xs;
		int x;
		s = charIndex('$',term,noT);
		xs = leads[0].set[i];
		x = charIndex(xs,term,noT);
		OPT[s][x]='<';
	}
	for(i=0;i<trails[0].len;i++)
	{
		char s,xs;
		int x;
		s = charIndex('$',term,noT);
		xs = trails[0].set[i];
		x = charIndex(xs,term,noT);
		OPT[x][s]='>';
	}
	int temp,varid;
	char var;
	for(i=0;i<noRules;i++)
	{
		int len = rules[i].num;
		char cx,cy,cz;
		int x,y,z;
		for(j=0;j<len;j++)
		{
			cx = rules[i].rhs[j];
			cy = rules[i].rhs[j+1];
			if(j<len-1)
				cz = rules[i].rhs[j+2];
			else
				cz = '\0';
			x = charIndex(cx,term,noT);
			y = charIndex(cy,term,noT);
			z = charIndex(cz,term,noT);
			
			if((!isNonTerminal(cx,noRules))&&(!isNonTerminal(cy,noRules)))
				OPT[x][y]='=';
			if((!isNonTerminal(cx,noRules))&&(isNonTerminal(cy,noRules))&&(!isNonTerminal(cz,noRules))&&(cz!='\0'))
				OPT[x][z]='=';
			if((!isNonTerminal(cx,noRules))&&(isNonTerminal(cy,noRules)))
			{
				temp=0;
				for(temp;temp<noNT;temp++)
					if(leads[temp].c==cy)
					break;
				for(k=0;k<leads[temp].len;k++)
				{
					var = leads[temp].set[k];
					varid = charIndex(var,term,noT);
					OPT[x][varid]='<';
				}	
			}
			if((isNonTerminal(cx,noRules))&&(!isNonTerminal(cy,noRules)))
			{
				temp=0;
				for(temp;temp<noNT;temp++)
					if(trails[temp].c==cx)
					break;
				for(k=0;k<trails[temp].len;k++)
				{
					var = trails[temp].set[k];
					varid = charIndex(var,term,noT);
					OPT[varid][y]='>';
				}	
			}	
		}
		//printf("\n");
		
	}
	printOPT(OPT,term);	
	return 0;
}