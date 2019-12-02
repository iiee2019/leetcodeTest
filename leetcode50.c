#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double myPow(double x, int n){
    double temp=1.0000;
    if(n>0){
        return pow(x,n);
    }else if(n<0){
        double m=fabs(n);
        temp=pow(x,m);
        return 1/temp;
    }else     
        return 1.0000;
}
int main(){ 
   double x=2.00000;
   int n=10;
   double res=myPow(x,n);
   printf("%f",res);
}
