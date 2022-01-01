#include <stdio.h>

int main(int argc, int **argv)
{
    int A, B;
    int C, D, E, F; 
    printf ("Basic nummeric operations with integers\n");
    printf ("========================================\n\n");
    printf ("Give first number  : ");
    scanf ("%d",&A);
    printf ("Give second number : ");
    scanf ("%d", &B);
    C = A + B;
    D = A - B;
    E = A * B;
    F = A / B;
    printf ("Add  : %d\n", C);
    printf ("Revision   : %d\n", D);
    printf ("Multiply  : %d\n", E);
    printf ("Division    : %d\n", F);
    return 0;
}