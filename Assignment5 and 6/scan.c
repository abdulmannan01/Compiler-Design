#define max 100
#define size 50
struct{

	char str[size];
}rule[size];
int count=0;
int scanGrammer(){
	FILE *fp;
	char fileName[size];
	printf("give the file name with extension\n");
	//strcpy(fileName,"aba.txt");
	scanf("%[^\n]",fileName);
	fp=fopen(fileName,"r");
	if(fp==NULL){
		printf("error: file not found");
		exit(0);
	}
	while(fgets(rule[count].str,size,fp)){
		printf(" %s",rule[count].str);
		count++;
	}
return 0;
}
