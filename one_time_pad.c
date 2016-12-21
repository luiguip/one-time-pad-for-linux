#include<stdio.h>
#define CIPHER(x,y) {x^=y;}

int main(int argc, char** argv){
	char mode[] = "rb+";
	int element;
	int key;
	fpos_t pos;
	if(argc<3){
		printf("Error: Missing arguments\n");
		return(-1);
	}
	FILE* file=fopen(argv[1],mode);
	FILE* pswd=fopen(argv[2],mode);
	if(!file || !pswd){
		perror("Error: ");
		return(-1);
	}
	while(!feof(file)){
		fgetpos(file,&pos);
		element=fgetc(file);
		key=fgetc(pswd);
		if(element!=EOF){
		  	CIPHER(element,key);
			fsetpos(file,&pos);
			fputc(element,file);
		}
	}
	fclose(file);
	fclose(pswd);
	return 0;
}

