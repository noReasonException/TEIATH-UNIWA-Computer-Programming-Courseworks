#include <stdio.h>
#include <math.h>
int main() {
    int a,b;
    printf("Insert two values! =-> ");
    scanf("%d%d",&a,&b);
    printf("\n-----------------------------------*\n");
    printf("Add->%d\r\n",a+b);
    printf("Rev->%d\n",a-b);
    printf("Mul->%d\n",a*b);
    printf("Div->%d\n",a/b);
    printf("Rem Div->%d\n",a%b);
    printf("Real Div->%4.2f\n",(float(a)/b));
    printf("Sqr->%d\n",a*a);
    printf("Sqrt->%f\n",sqrt(b));
    printf("-----------------------------------*");
    scanf("%d",&a);
}