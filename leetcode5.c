void help(char * s,int N,int left,int right,int *start,int *len){
    int lNum=left;
    int rNum=right;
    while(lNum>=0&&rNum<N&&s[lNum]==s[rNum]){
        lNum--; // 计算以left和right为中心的回文串长度
        rNum++;
    }
    if(rNum-lNum-1>*len){  // 如果找到更长的子串，保存其信息
        *start=lNum+1;
        *len=rNum-lNum-1;
    }
}
char * longestPalindrome(char * s){
    if(s==NULL){
        return NULL;
    }
    int N=strlen(s);
    int start=0;
    int len=0;
    for(int i=0;i<N;i++){  //奇数长度的回文子串
        help(s,N,i-1,i+1,&start,&len);
    }
    for(int i=0;i<N;i++){  //偶数长度的回文子串
        help(s,N,i,i+1,&start,&len);
    }
    s[start+len]='\0';
    return s+start;
}
