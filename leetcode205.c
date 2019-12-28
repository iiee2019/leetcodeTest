bool isIsomorphic(char * s, char * t){
    int arrs[128]={0};
    int arrt[128]={0};
    int lens=strlen(s);
    int lent=strlen(t);
    if(lens!=lent)
        return false;
    for(int i=0;i<lens;i++){
        if(arrs[s[i]]!=arrt[t[i]]){
            return false;
        }
        arrs[s[i]]=i+1;
        arrt[t[i]]=i+1;
    }
    return true;
}
