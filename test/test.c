#include<stdio.h>
#include<stdlib.h>




int main(){
    int num1=1,num2=13;
    char test[6]="hello";
    char test2[4]="hey";
    FILE *fp=fopen("/home/bssayla/Downloads/Project/database/clients.txt","a+");
    do{
        fprintf(fp,"%d , %s , %d , %s \n",num1,test,num2,test2);
        printf("%d %s %d %s\n",num1,test,num2,test2);
    }while(num1++<10);
}