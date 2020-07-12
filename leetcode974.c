int subarraysDivByK(int* A, int ASize, int K){
    if(A==NULL||ASize==0){
        return 0;
    }
    int* dp=(int*)malloc(sizeof(int)*(ASize+1));
    memset(dp,0,(ASize+1)*sizeof(int)); 
    dp[0] = 0;
    int count = 0;
    for(int i=0;i<ASize;i++){
        dp[i+1]=dp[i]+A[i];
    }
    int *arr = (int *)malloc(K * sizeof(int));
    memset(arr, 0, K * sizeof(int));
    for (int i = 0; i < ASize + 1; i++) {
        arr[(dp[i] % K + K) % K]++;
    }
    for (int i = 0; i < K; i++) {
        count = count + (arr[i] * (arr[i] - 1)) / 2;
    }
    return count;
}
