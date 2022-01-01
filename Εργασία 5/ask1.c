#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define pi 3.14159265359

double  convert(double degrees) {return degrees*pi/180;}



double sin2(double x){
    double sum=x;
    double prev_term = x;
    signed int sign=-1;
    signed int i=0;
    signed int fact=3;
    while (sum+prev_term-sum>0.00000001){
        prev_term*=(x*x)/(((fact-1)*fact));
        fact+=2;
        sum+=sign*prev_term;
        sign=-sign;
    }
    return sum;

}
double cos2(double x){
    double sum=1;
    double prev_term = 1;
    signed int sign=-1;
    signed int i=0;
    signed int fact=2;
    while (sum+prev_term-sum>0.00000001){
        prev_term*=(x*x)/(((fact-1)*fact));
        fact+=2;
        sum+=sign*prev_term;
        sign=-sign;
    }
    return sum;

}

int main(){
    double degrees=45;
    double rad = convert(degrees);
    printf("%lf\n",cos2(rad));
    printf("%lf\n",cos(rad));
}