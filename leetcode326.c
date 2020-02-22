bool isPowerOfThree(int n){
   int num=n;
   while(num&&num%3==0){
       num/=3;
   }
   return num==1;
}
