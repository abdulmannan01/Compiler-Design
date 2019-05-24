struct{
	char str[size];
	char index;
}token[max];
int tokenCount=0;
void scanToken(char str[max]);

int inputScan(){

 	char str[max]="w(n=n)bn=n+n;e";
	scanToken(str);
	printf("\nno. of tokens are: %d\n",tokenCount);
return 0;
}
void scanToken(char str[max]){

	int length,index;
	length=strlen(str);

	for(int i=0;i<length;){

		index=0;
		if(str[i]>96){
			while(str[i]>96){
				token[tokenCount].str[index]=str[i];
				i++,index++;
			}
			token[tokenCount].index=tokenCount;
			tokenCount++;
		}
		else if(str[i]<91 && str[i]>64){
		
			token[tokenCount].str[index]=str[i];
			token[tokenCount].index=tokenCount;
			tokenCount++;
			i++;	
		}
		else if(str[i]<64 && str[i]!=';'){
			token[tokenCount].str[index]=str[i];
			token[tokenCount].index=tokenCount;
			tokenCount++;
			i++;
		}
		else i++;
		//printf("token count %d",tokenCount);
		
	}printf("tokens of input string are\n");
	for(int i=0;i<tokenCount;i++){

		//printf("%d: %s\t",token[i].index,token[i].str);
	}

}
















