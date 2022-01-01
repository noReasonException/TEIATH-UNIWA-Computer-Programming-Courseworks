#include <stdio.h>
#include <math.h>
#define pi 3.14159

//Forward Declarations
void PrintSurfaceofCube(double Meters);
void PrintVolumeOfCube(double Meters);
void PrintSurfaceofSphere(double Meters);
void PrintVolumeOfSphere(double Meters);


int main(){
    double Meters;
    scanf("%lf",&Meters);
    PrintSurfaceofCube(Meters);
    PrintVolumeOfSphere(Meters);
    printf("*-------------------------------------*\n");
    PrintSurfaceofSphere(Meters);
    PrintVolumeOfSphere(Meters);
}

void PrintSurfaceofCube(double Meters){
    printf("Surface Cube-> %4.2lf \n",6*pow(Meters,2));
}
void PrintVolumeOfCube(double Meters){
    printf("Volume Cube %4.2lf \n",pow(Meters,3));
}
void PrintSurfaceofSphere(double Meters){
    printf("Surface Sphere-> %4.2lf \n",(4*pi*pow(Meters,2)));
}
void PrintVolumeOfSphere(double Meters){
    printf("Volume Sphere->%4.2lf \n",(4./3)*pi*pow(Meters,3));
}