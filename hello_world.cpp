#include <stdio.h>
int main(){
   char name[100];
   //printf("What is your name?\n");
   //scanf("%s",name);
   //printf("Hello,%s,nice to meet you!\n",name);
   char ch[2][5]={"1234","5678"},(*p)[5];
   int i,j,s=0;
   p=ch;
   for(i=0;i<2;i++)
      for(j=0;*(*(p+i)+j)!='\0';j++)
         s+=p[i][j]-'0';
   printf("%d\n",s);
}