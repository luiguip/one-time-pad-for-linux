#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(int argc, char* argv[]){

	time_t t;
	int key;
	if(argc !=2){
		printf("Error: 1 arguments are required");
		return(-1);
	}

	FILE* file = fopen(argv[1],"rb");
	char* pswdtxt=strcat(argv[1],".key");
	FILE* pswd = fopen(pswdtxt,"w+b");
	if(!file || !pswd){
		perror("Error");
		return(-1);
	}
	srand(time(&t));
	while(!feof(file)){
		key=rand()%255;
		fputc(key,pswd);
		fgetc(file);
	}
	return 0;
}
