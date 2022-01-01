
#include <stdio.h>
int main() {
    int n,i,temp,positive_numbers=0,neg_multiply=1,evenumber=0;
    double mo_positive=0l;

    do{
        scanf("%d",&temp);
        if(!temp)break;
        if(temp>0){
            positive_numbers+=1;
            mo_positive+=temp;
        }
        else neg_multiply*=temp;

        if(temp%2==0)evenumber+=1;
        else printf("pow of this number is %d\n",temp*temp);
    }while (temp!=0);

    if(positive_numbers==0)printf("No positive numbers given!\n");
    else printf("Positive M.O -> %3.2lf\n",mo_positive/positive_numbers);

    if(neg_multiply==1)printf("No negative numbers given\n");
    else printf("Negative Multiplications -> %d\n",neg_multiply);

    if(evenumber==0)printf("No even NUmber given!\n");
    else printf("Even Numbers -> %d",evenumber);
}