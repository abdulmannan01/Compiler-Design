#include"parsingTable.c"
int expand(int index);
int isLL1(int index);
void parser(void);
char input[size];int stackTop;char stack[size];
int main(){

	int length,flag;
	falloww();
	//printf("first of S %s\n",first[S].str);
	length=strlen(nonTerminals);
	//printf("no of non terminal....%d\n",length);
	for(int i=0;i<length;i++){

		flag=isLL1(i);
		//printf("flag: %d\n",flag);
		if(flag==0){
			printf("error:ambigous:: LL1 parsing cant be possible\n");
			exit(0);
		}
	}
	if(flag!=0){
		mainn();
		parser();
	}
return 0;
}
int isLL1(int index){

	int length1,length2,flag;
	length1=strlen(follow[index].str)-1;
	length2=strlen(first[index].str)-1;
	//printf("length1 %d length2 %d\n",length1,length2);
	for(int i=0;i<length2;i++){

		for(int j=0;j<length1;j++){
			//printf("checking %c %c\n",follow[index].str[j],first[index].str[i]);
			if(follow[index].str[j]==first[index].str[i]){	
				printf("in rule:%d::  common terminal in first and follow: %c\n",index,follow[index].str[j]);
				return 0;
			}
		}
	}
return 1;
}
void parser(void){

	int length,index=0,flag1,flag2;	
	static char inputFilter[size];
	printf("give input\n");
	//strcpy(input,"aba");
	scanf(" %[^\n]",input);
	length=strlen(input);
	printf("input tokens are\n");
	for(int i=0;i<length;i++){

		if(input[i]>90 || input[i]<65 && input[i]!=';'){
			inputFilter[index]=input[i];
			printf("%c\t",inputFilter[index]);
			index++;
		}
	}
	strcpy(input,inputFilter);
	printf("\n %s %d\n",input,index);
	length=strlen(rule[0].str)-1;
	printf("length of rule[0] %d\n",length);
	stackTop=-1;
	for(int i=length-1;i>0;i--){	
		stackTop++;
		printf("stack-----%c stackTop %d i %d\n",rule[0].str[i],stackTop,i);	
		stack[stackTop]=rule[0].str[i];
		
	}
	
	printf("stack-----%s stackTop %d\n",stack,stackTop);
	for(int i=0;i<index;i++){//index: number of input terminals

		if(stack[stackTop]>64 && stack[stackTop]<91){

			//printf("non terminal...\n");			
			flag1=find(stack[stackTop]);
			length=strlen(terminal);
			for(int j=0;j<length;j++){

				if(input[i]==terminal[j])	flag2=j;
			}			
			flag2=(int)parsingTable[flag1][flag2]-48;
			//printf("from table %c flag1:%d flag2 %d length %d\n",stack[stackTop],flag1,flag2,length);			
			if(flag2>-1){
				expand(flag2);
				i--;
			}
			else{

				printf("error: can't be parse: undefined non Terminal: %c\n",rule[flag1].str[0]);
				exit(0);
			}
		}
		else if(stack[stackTop]<65 || stack[stackTop]>90 && stack[stackTop]==input[i]){
			printf("terminal %d of %s:%c matched :stack->%s\n",i,input,input[i],stack);
			int null=stackTop,l;
			l=strlen(stack);
			for(int i=0;i<l;i++){
				stack[null]=' ';null++;
			}
			stackTop--;
		}
		else{
			printf("wrong input:'%c' not matched with '%c' parsing can't be possible\n",input[i],stack[stackTop]);
			exit(0);
		}
	}
	
printf("parsing successfull\n");
}
int  expand(int index){//index:index of recent input terminal,stackTop: use to expand non terminal on top of stack

	/*since count is used to represent total number of rule so in this function we have to expand non terminal at top of the stack with 		appropriate rule correspond to recent input symbel */
	
	int length;
	length=strlen(rule[index].str)-1;
	//	printf("\n\nin ex[pand......................%s: length %d stackTop %d\n\n",rule[index].str,length,stackTop);
	for(int i=length-1;i>0;i--){
		stack[stackTop]=rule[index].str[i];
		stackTop++;
	}
	stackTop--;
return 0;
}