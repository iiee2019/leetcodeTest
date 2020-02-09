
#include <math.h>

int integerBreak(int n){
    if(n<=3){
        return n-1;
    }
    int m=floor(n/3);
    int flag=n%3;
    if(flag==0){
        return pow(3,m);
    }else if(flag==1){
        return 4*pow(3,(m-1));
    }else{
        return 2*pow(3,m);
    }
}
