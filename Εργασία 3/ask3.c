#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void solve1(int status);
void  solve2(double b , double c);
void  solve3(double a,double b , double c);

int main (int NoP, char **Params)
{

    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);

    if(a==0l&&b==0l&&c==0l)
        solve1(1);
    else if(a==0l&&b==0l)
        solve1(0);
    else if(a==0l)
        solve2(b,c);
    else
        solve3(a,b,c);

    return 0;

}
void solve1(int status){
    printf("This equation %s",status?("has unlimited solve numbers"):("is not possible to solve"));

}
void solve2(double b,double c){
    printf("This equation has one solve number -> %5.3lf",-(c/b));
}
void  solve3(double a,double b , double c){
    double dis = (b*b)-4*a*c,x1,x2;
    if(dis<0){
        printf("This equation cannot been solved (discriminant < 0 )");
    }
    else if(dis==0){
        printf("This equation has double solve the number %4.2lf",-(b/(2*a)));
    }
    else{
        x1=((-b)+sqrt(dis))/(2*a);
        x2=((-b)-sqrt(dis))/(2*a);

        printf("This equation has solve the numbers x1=%4.2lf and x2=%4.2lf ",x1,x2);

    }

}