#include<stdio.h>
int count;
void tower(char from,char temp,char to,int n){
    if(n==0)return;
    tower(from,to,temp,n-1);
    printf("Move disk %d from %c to %c\n",n,from,to);
    count++;
    tower(temp,from,to,n-1);
}
int main(){
    char L,R,C;
    int n ;
    scanf("%d",&n);
    tower('L','C','R',n);
    printf("Total no. of steps are %d",count);
}