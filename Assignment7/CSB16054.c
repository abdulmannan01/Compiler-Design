#include<stdio.h>
#include<string.h>
void main(){

char table[20][20][20],ter[20],stack[20],ip[20],st1[20],pro[20][20],num;
int i,j,t,k,top=0,st,col,row,pop,np,no,len;

for(i=0;i<20;i++){
ter[i]=NULL;
stack[i]=NULL;
ip[i]=NULL;
st1[i]=NULL;
for(j=0;j<20;j++){
pro[i][j]=NULL;
for(k=0;k<20;k++)
{
table[i][j][k]=NULL;
}
}
}
printf("Enter the no of productions:");
scanf("%d",&np);
printf("Enter the productions:");
for(i=0;i<np;i++)
{
scanf("%s",pro[i]);                                           
}
printf("Enter the no.of states:");
scanf("%d",&st);
printf("Enter the states:");
scanf("%s",st1);
printf("Enter the no of terminals:");
scanf("%d",&t);
printf("Enter the terminals:");
scanf("%s",ter);
for(i=0;i<st;i++)
{
for(j=0;j<t;j++)
{
printf("\nEnter the value for %c %c:",st1[i],ter[j]);
scanf("%s",table[i][j]);
}
}
printf("\nSLR TABLE:\n");
for(i=0;i<t;i++)
{
printf("\t%c",ter[i]);
}
for(i=0;i<st;i++)
{
printf("\n\n%c",st1[i]);
for(j=0;j<t;j++)
{
printf("\t%s",table[i][j]);
}
}

stack[top]='a';
printf("\nEnter the input string:");
scanf("%s",ip);
i=0;
printf("\n\nSTACK\t\tINPUT STRING\t\tACTION\n");
printf("\n%s\t\t%s\t\t",stack,ip);
while(i<=strlen(ip) )
{
for(j=0;j<st;j++)
{
if(stack[top]==st1[j])
col=j;
}
for(j=0;j<t;j++)
{
if(ip[i]==ter[j]) 
{
row=j;
}
}
if((stack[top]=='b')&&(ip[i]=='$')){printf("\nSUCCESS");break;}
else if(table[col][row][0]=='s')
{
top++;
stack[top]=ter[row];
top++;
stack[top]=table[col][row][1];
i++;
printf("Shift %c %d\n",ter[row],table[col][row][1]);
}
else if(table[col][row][0]=='r')
{
no=(int)table[col][row][1];
no=no-48;
len=strlen(pro[no]);
len=len-3;
pop=2*len;
printf("POP %d",pop);
for(j=0;j<pop;j++)
{
top=top-1;
}
top++;
stack[top]=pro[no][0];
k=top;
k=k-1;
printf(" Push [%c,",pro[no][0]);
for(j=0;j<st;j++)
{
if(stack[k]==st1[j])
{
col=j;
}
}
k++;
for(j=0;j<t;j++)
{
if(stack[k]==ter[j])
{
row=j;
}
}
top++;
stack[top]=table[col][row][0];
printf("%c]\n",table[col][row][0]);
}
else{printf("\nFAILURE");break;
}
printf("\n");
for(j=0;j<=top;j++)
{
printf("%c",stack[j]);
}
printf("\t\t");
for(j=i;j<strlen(ip);j++)
{
printf("%c",ip[j]);
}
printf("\t\t");
}

}