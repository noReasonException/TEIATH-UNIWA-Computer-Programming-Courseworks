#include <stdio.h>

int main(){
    int size,i,j,n,d;
    scanf("%d",&size);
    for(i=0;i<=size;i++){
        for(j=0;j<i;j++){
            printf("*");
        }
        printf("\n");
    }
    for(i=0;i<=size;i++){
        for(j=0;j<size-i;j++){
            printf(" ");
        }
        for(j=size-i;j<=size;j++){
            printf("*");
        }
        printf("\n");
    }
    for(i=0;i<=size;i++){
        for(j=0;j<size-i;j++){
            printf(" ");
        }
        for(j=size-i;j<=size+i;j++){
            printf("*");
        }
        printf("\n");
    }
    for(i=0;i<=size;i++){
        for(j=0;j<=size;j++){
            if(i==0 or j==0 or i==size){ printf("X"); }
            if(i==j and i!=0 and j!=size){
                for(n=0;n<size;n++){
                    if(i==size/2 and size%2==0){for(d=n;d<size/2;d++)printf(" ");printf("*");for(;d<size-1;d++)printf(" ");break;}
                    if(n==j xor n+i==size ){printf("*");continue;}
                    printf(" ");
                }
            }
            if(j==size)printf("X");
        }
        printf("\n");
    }
}