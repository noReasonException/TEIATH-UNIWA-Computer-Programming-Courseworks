#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int comb(int *arr,int *data,int start,int end,int index,int r){
    int i;
    if(index==r){
        for (i=0;i<r;i++) {
            printf(" %d ",data[i]);
        }
        printf("\n");
    }
    else{
        for(i=start;i<end;i++){
            data[index]=arr[i];
            comb(arr,data,i+1,end,index+1,r);
        }
    }
}
int main() {
    int AmountOfNumbers,i,temp,choose;
    printf("Give the amound of numbers-> ");
    scanf("%d",&AmountOfNumbers);
    int *Numbers = (int *)malloc(sizeof(int)*AmountOfNumbers);
    for (i=0;i<AmountOfNumbers;i++){
        printf("%d)Give Number-> ",i);
        scanf("%d",&temp);
        Numbers[i]=temp;
    }
    printf("%d choose? -> ",AmountOfNumbers);
    scanf("%d",&choose);
    int *data = (int *)malloc(sizeof(int)*choose);
    comb(Numbers,data,0,AmountOfNumbers,0,choose);

}
