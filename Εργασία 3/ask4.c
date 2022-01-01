#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int Max=a,pos=1;
    Max = ((b>Max?Max=b,pos=2:Max),(c>Max?c=Max,pos=3:Max));
    printf("%d %d",Max,pos);
}