#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int addDigits(int num){
    if(num<=9)
        return num;
    else if(num%9==0)
        return 9;
    else
        return num%9;
}

int main(){
  int x=38;
   int res=addDigits(x);
   printf("%d",res);
}

