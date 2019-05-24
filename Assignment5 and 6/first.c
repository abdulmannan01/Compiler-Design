#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"terminal.h"
#include"scan.c"
struct{
	char str[max];
}first[size];
char returnString[size];
int find(char term);
int mergeDuplicate(int index);
int removeSpace(int index);
int checkAdd(int index1,int index2);
int checkLeadAdd(char str[size],char term[size]);
int firstt(){

	int i,indexTerminal,flag,flag1;
	int indexLeading1,indexLeading2;
	static char term[max],nul[max];
	static char check1[max],check2[max],check3[max],check4[max];
	//printf("before scanning grammer: first set are\n ");
	for(int i=0;i<4;i++){
				
		//printf("\t %d:\t%s\n",i,first[i].str);
	}
	scanGrammer();
	printf("total number of rules: %d\n",count);
	//printf("grammer scaned\n");
	while(1){
	//printf("inside while\n");
		 strcpy(check1,check2);
		 strcpy(check3,check4);
		for(i=0;i<count;i++){
		
			indexTerminal=1;
			strcpy(term,"             ");
			
			 if(rule[i].str[indexTerminal]<65 || rule[i].str[indexTerminal]>91){
				//S->aX
				term[indexTerminal-1]=rule[i].str[indexTerminal];
				
				if(rule[i].str[0]=='A'){
					checkLeadAdd(first[A].str,term);
				}
				else if(rule[i].str[0]=='C'){
					checkLeadAdd(first[C].str,term);
				}
				else if(rule[i].str[0]=='S'){
					checkLeadAdd(first[S].str,term);
				}
				else if(rule[i].str[0]=='E'){
					checkLeadAdd(first[E].str,term);
				}
			}
			else if(rule[i].str[indexTerminal]>64 && rule[i].str[indexTerminal]<91){
				//S->AX
				indexLeading1=find(rule[i].str[0]);//left side non terminal
				indexLeading2=find(rule[i].str[1]);// right side non terminal
				checkAdd(indexLeading1,indexLeading2);
			}

			
			if(i==count-1){
				
				strcpy(check2,first[0].str);
				strcpy(check4,first[1].str);	
			}
		}
		
		flag=strcmp(check1,check2);
		flag1=strcmp(check3,check4);
		//printf("check1 %s  %s \nchaeck 2%s %s\n\n\n\n",check1,check2,check3,check4);
		if(flag==0 && flag1==0){
			printf("first sets are\n");
			break;
		}
		
	}

	for(int i=0;i<4;i++){

		mergeDuplicate(i);
		removeSpace(i);				
		printf("\t %d: %c\t%s\n",i,nonTerminals[i],first[i].str);
	}
return 0;	
}
int find(char term){
	//printf("finding non terminal indices\n");
	if(term=='A')
		return A;
	else if(term=='C')
		return C;
	else if(term=='S')
		return S;
	else if(term=='E')
		return E;
	else return -1;
}
int checkAdd(int index1,int index2){//str:leading set;index : index in leading set; result: return leading setwhich are not in leading[index]

	
	if(index1!=index2)
		checkLeadAdd(first[index1].str,first[index2].str);
return 0;
}
int checkLeadAdd(char str1[size],char str2[size]){

	int length1,length2,backupLength;
	length1=strlen(str1);
	length1--;
	length2=strlen(str2);
	length2--;
	backupLength=length2;
	
	for(int i=length1;i>=0;i--){

		if(length2==-1)
			i=0;
		else if(str1[i]==str2[length2])
			length2--;
		else	length2=backupLength;
	}
	length2++;
	if(length2==0){
	
		
	}
	else {strcat(str1,str2);  }
return 0;
}
int mergeDuplicate(int index){


	int length;
	length=strlen(first[index].str);
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){

			if(first[index].str[i]==first[index].str[j] && i!=j){
			 	first[index].str[i]=' ';
			}
		}	
	}
	
return 0;
}
int removeSpace(int index){

	int count=0,l;
	char str[max]="";
	l=strlen(first[index].str);	
	for(int i=0;i<l;i++){

		if(first[index].str[i]!=' '){
			str[count]=first[index].str[i];
			count++;
		}
	}
	str[count]=' ';
	strcpy(first[index].str,str);
	
return 0;
	
}


















