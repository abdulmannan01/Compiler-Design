#include"follow.c"
void search(char ch,int indexParse);
char parsingTable[size][size];
char terminal[size];
int checkLeadAddd(char str1[size],char str2[size]);
int mainn(){

	int length,indexTerminal=0;
	static char term[size],spaceRemoval[size];
	printf("\nLL1 parsing table is:\n");
	printf("\t");
	for(int i=0;i<count;i++){

		length=strlen(rule[i].str)-1;
		for(int j=1;j<length;j++){
			strcpy(term,"        ");
			if(rule[i].str[j]<65 || rule[i].str[j]>90 && rule[i].str[j]!=10){

				term[0]=rule[i].str[j];
				checkLeadAddd(terminal,term);
				//removeSpaceee();//to prevent from segmentation fault
				indexTerminal++;				
			}
		}
	}//this part is used to remove all space which is in between terminals
	length=strlen(terminal);//length before removal of space
	 indexTerminal=0;	
	for(int i=0;i<length;i++){

		if(terminal[i]!=' '){
			spaceRemoval[indexTerminal]=terminal[i];
			indexTerminal++;
		}
	}
	strcpy(terminal,spaceRemoval);
	//indexTerminal : number of terminals
	//printf("\nterminal %s length %d\n\t",terminal,indexTerminal);
	for(int i=0;i<indexTerminal;i++){
		printf("%c\t",terminal[i]);
		search(terminal[i],i);
	}
	printf("\n\n");
	for(int i=0;i<4;i++){// 4: number of non terminal
		printf("%c\t",nonTerminals[i]);
		for(int j=0;j<indexTerminal;j++){//length: number of terminal

			printf("%c\t",parsingTable[i][j]);			
		}printf("\n\n");
	}
return 0;
}
void search(char ch,int indexParse){

	int length1,length2;
	int lengthNonTerminal=strlen(nonTerminals);
	//printf("in search\n\n");
	for(int i=0;i<lengthNonTerminal;i++){	
		length1=strlen(first[i].str);
		for(int j=0;j<=length1;j++){

			if(first[i].str[j]==ch){
				parsingTable[i][indexParse]=(char)i+48;
			}
			
		}
		length2=strlen(follow[i].str);
		for(int j=0;j<length2;j++){

			if(follow[i].str[j]==ch){
				parsingTable[i][indexParse]=(char)i+48;
			}
			
		}
	}
}
int checkLeadAddd(char str1[size],char str2[size]){
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
	else {strcat(str1,str2);}
return 0;
}










