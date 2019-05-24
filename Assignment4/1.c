#include <stdio.h>
#include <stdlib.h>
int count=0;
char inp[100];
int check(char c,char x){
	if(c==x){
		count++;		//if match: then move to next input
		return 1;
	}
	return 0;
}
int E(){
	int ocount=count;
	if(check('n',inp[count])){
		if(check('*',inp[count])){
			if(check('n',inp[count])){
				return 1;
			}
		}
	}
	count=ocount;
	if(check('n',inp[count])){
                if(check('+',inp[count])){
                        if(check('n',inp[count])){
                                return 1;
                        }
                }
        }
	count=ocount;
	if(check('n',inp[count])){
                if(check('-',inp[count])){
                        if(check('n',inp[count])){
                                return 1;
                        }
                }
        }
	count=ocount;
	if(check('n',inp[count])){
                if(check('/',inp[count])){
                        if(check('n',inp[count])){
                                return 1;
                        }
                }
        }
	return 0;
}
int D(){
	int ocount=count;
	if(check('n',inp[count])){
		if(check('=',inp[count])){
			if(E()){
				return 1;
			}
		}
	}
	return 0;
}
int A(){
	int ocount=count;
	if(D()){
		if(check(';',inp[count])){
			if(A()){	
				return 1;
			}
		}
	}
	count=ocount;
	if(check('e',inp[count]))
		return 1;
	return 0;
}
int B(){
	int ocount=count;
	if(check('p',inp[count])){
		return 1;
	}
	count=ocount;
	if(check('q',inp[count])){
		return 1;
	}
	return 0;
}
int C(){
	if(check('n',inp[count])){
		if(B()){
			if(check('n',inp[count])){
				return 1;
			}

		}
	}
	return 0;
}
int S(){
	if(check('w',inp[count])){
		if(check('(',inp[count])){
			if(C()){
				if(check(')',inp[count])){
					if(check('b',inp[count])){
						if(A()){
							return 1;
						}
					}
				}

			}
		}
	}
	return 0;

}
int main(){
	int i;
	printf("Enter the input string: ");
	scanf("%s",inp);
	if(S()){
		printf("Valid input!!!\n");
	}
	else
		printf("Invalid input!!!\n");



}