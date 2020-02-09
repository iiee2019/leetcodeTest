int countPrimes(int n){
    int* isPrim=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        isPrim[i]=1;
    }
    for (int i = 2; i * i < n; i++){
        if (isPrim[i]) {
            for (int j = i * i; j < n; j += i){ 
                isPrim[j] = 0;
            }
        }
    } 
    int count=0;
    for(int i=2;i<n;i++){
        if(isPrim[i]){
            count++;
        }
    }
    return count;
}
