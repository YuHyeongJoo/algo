#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void push_back(int *arr,int n);
int main(){

        FILE *fp = fopen("hw6_data.txt","r");
        int arr[21][21];
        int adj[20][20];
        int transpose[20][20];
        for(int i=0; i<20; i++){
          for(int j=0; j<20; j++){
            transpose[i][j]=0;
            adj[i][j]=0;
          }
        }
        int line=0;
        char c;
        while((c=fgetc(fp))!=EOF)
                if(c=='\n') line++;
       
        rewind(fp);
        char tmp[255];
        fgets(tmp,255,fp);
        char *ptr ;
        int i;
        char tmp2[3];

        for(int k=0; k<line; k++){
          fgets(tmp,255,fp);
         // printf("%s\n",tmp);
          ptr = strtok(tmp," ");
          i=0;
          while(ptr != NULL){
                int num;
                strcpy(tmp2,ptr);
               
                if(tmp2[0]>64)
                  ;
                else  {
                  num=tmp2[0]-48;
                  arr[k][i]= num;
                  i++;
                }
                                                  
              ptr= strtok(NULL," ");
          }
          arr[k][line-1]=tmp2[0]-48;
        
        }
        for(int i=0; i<line; i++){
          for(int j=0; j<line; j++){
            if(arr[i][j]==1){
             // adj[i][j]=arr[i][j]+64+j;
              push_back(adj[i],65+j);
              push_back(transpose[j],i+65);
            }
            
              
            
          }
          
        }
   	printf("adj list\n");    
         for(int i=0; i<line; i++){
           printf("%c: ",65+i);
          for(int j=0; j<line; j++){
            printf("%c ",adj[i][j]);
          }
          printf("\n");
         }
          printf("\ntranspose list\n");
         for(int i=0; i<line; i++){
           printf("%c: ",65+i);
          for(int j=0; j<line; j++){
            printf("%c ",transpose[i][j]);
          }
          printf("\n");
         }
      
        
        
        fclose(fp);

}

void push_back(int *arr,int n){
  int c=0; 
  int i=0;
  while(1){
    if(arr[i]==0) break;
    if(arr[i]!=0){
      c++;
    }
    i++;
  }
  arr[c]=n;
}
