#include"first.c"
int removeSpacee(int index);
int mergeDuplicatee(int index);
struct{
	char str[max];
}follow[size];

int falloww(){
	firstt();
	int i,indexTerminal,flag,flag1;
	int indexLeading1,indexLeading2;
	static char term[max],nul[max];
	static char check1[max],check2[max],check3[max],check4[max];
	//printf("before scanning grammer: follow set are\n ");
	 
	while(1){
		 strcpy(check1,check2);
		 strcpy(check3,check4);
		for(i=0;i<count;i++){
		
			indexTerminal=strlen(rule[i].str);
			strcpy(term,"                 ");
			
			for(int j=1;j<=indexTerminal;j++){
				//printf("indextTerminal: j:%d %d %c \n",j,indexTerminal,rule[i].str[j]);
if(rule[i].str[j]>64 && rule[i].str[j]<91 && (rule[i].str[j+1]>91 || rule[i].str[j+1]<65) && rule[i].str[j+1]!=10){//10AsciiOf:linefeed
					//XBb
					//printf("case: XBb\n");
					term[0]=rule[i].str[j+1];
					indexLeading2=find(rule[i].str[j]);
					checkLeadAdd(follow[indexLeading2].str,term);
				}

else if(rule[i].str[j]>64 && rule[i].str[j]<91 && (rule[i].str[j+1]>91 || rule[i].str[j+1]<65) && rule[i].str[j+1]==10){
					//S->XB
					//printf("case: S->XB\n");
					indexLeading1=find(rule[i].str[0]);
					indexLeading2=find(rule[i].str[j]);
					//printf("index2 %d %c\n",indexLeading2,rule[i].str[j]);
					checkLeadAdd(follow[indexLeading2].str,follow[indexLeading1].str);
				}
				else if(rule[i].str[j]>64 && rule[i].str[j]<91 && rule[i].str[j+1]>64 && rule[i].str[j+1]<91){
					//XBS
					//printf("case: XBS\n");
					indexLeading1=find(rule[i].str[j]);
					indexLeading2=find(rule[i].str[j+1]);
					checkLeadAdd(follow[indexLeading1].str,first[indexLeading2].str);
				}
			

			}
	
			if(i==count-1){
				
				strcpy(check2,follow[0].str);
				strcpy(check4,follow[1].str);	
			}
		}
		
		flag=strcmp(check1,check2);
		flag1=strcmp(check3,check4);
		//printf("check1 %s  %s \nchaeck 2%s %s\n\n\n\n",check1,check2,check3,check4);
		if(flag==0 && flag1==0){
			printf("follow sets are\n");
			break;
		}
		
	}

	for(int i=0;i<4;i++){

		mergeDuplicatee(i);
		removeSpacee(i);				
		printf("\t %d:%c\t%s\n",i,nonTerminals[i],follow[i].str);
	}
return 0;	
}
int mergeDuplicatee(int index){


	int length;
	length=strlen(follow[index].str);
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){

			if(follow[index].str[i]==follow[index].str[j] && i!=j){
			 	follow[index].str[i]=' ';
			}
		}	
	}
	
return 0;
}
int removeSpacee(int index){

	int count=0,l;
	char str[max]="";
	l=strlen(follow[index].str);	
	for(int i=0;i<l;i++){

		if(follow[index].str[i]!=' '){
			str[count]=follow[index].str[i];
			count++;
		}
	}
	str[count]=' ';
	strcpy(follow[index].str,str);
	
return 0;
	
}

