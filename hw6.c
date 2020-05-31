#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	FILE *fp = fopen("hw6_data.txt","r");
	int arr[21][21];
	int line=0;
	char c;
	while((c=fgetc(fp))!=EOF)
		if(c=='\n') line++;
	printf("line:%d\n",line);
	rewind(fp);
	for(int i=0; i<line; i++){
		fscanf(fp,"%d ", &arr[0][i]);
	}
	for(int i=0; i<line; i++){
		printf("num: %d  ",arr[0][i]);
	}
	fclose(fp);
  
}

