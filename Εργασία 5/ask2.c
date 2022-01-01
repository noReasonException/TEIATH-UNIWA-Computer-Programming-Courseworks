#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

int factorial (int a){if(a==0||a==1)return 1;return a*(factorial(a-1));}
int factorial_check_value(int number){return number>=0?1:0;}
int combination_check_numbers(int a,int b){return a>=b&&a>0&&b>0?1:0; }
int combination(int a,int b){return factorial(a)/(factorial(b)*(factorial(a-b)));}


int main_menu(int a,int b){
    int ch,i;
    int choices[4],non_correct_choices=0;
    memset(choices,0,3*sizeof(int));
    do{
        printf("*************Menu***************\n");
        printf("1)Count power a ^ b\n");
        printf("2)Count a! and b!\n");
        printf("3)Calculate a in b combinations\n");
        printf("4)Exit\n");
        printf("Enter a valid choice->");
        scanf("%d",&ch);
        if(ch>0 && ch<5){
            if(ch==1){
                printf("%d^%d=%.0lf\n",a,b,pow(a,b));
            }
            if(ch==2){
                if(factorial_check_value(a)){
                    printf("%d!=%d\n",a,factorial(a));
                }
                else{
                    printf("%d is not valid number\n",a);
                }
                if(factorial_check_value(b)){
                    printf("%d!=%d",b,factorial(b));
                }
                else{
                    printf("%d is not valid number\n",b);
                }

            }
            if(ch==3){
                if(combination_check_numbers(a,b)){
                    printf("Combination a per b is %d\n",combination(a,b));
                }
                else{
                    printf("Invalid numbers given\n");
                }
            }
            choices[ch]+=1;
        }
        else{
            non_correct_choices+=1;
        }

    }while(ch!=4);
    for(i=1;i<4;i++){
        printf("User choiced %d number %d times..\n",i,choices[i]);

    }
    printf("User choiced non valid values %d times",non_correct_choices);
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    main_menu(a,b);
}