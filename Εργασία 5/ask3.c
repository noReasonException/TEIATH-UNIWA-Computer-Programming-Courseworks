#include <stdio.h>


int hanoi (int n , int source ,int dest ,int spare){
    if(n==1){
        printf("%d->%d\n",source,dest);
    }
    else{
        hanoi(n-1,source,spare,dest);
        printf("%d->%d\n",source,dest);
        hanoi(n-1,spare,dest,source);

    }

}
int main() {
    hanoi(3,1,2,3);
    return 0;
}