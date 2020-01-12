bool isAnagram(char * s, char * t){
    int len1=strlen(s);
    int len2=strlen(t);
    if(len1!=len2){
	return false;
    }
    int str1[26]={0};
    for(int i=0;i<len1;i++){
        str1[s[i]-'a']++;
    }
    for(int i=0;i<len2;i++){
        str1[t[i]-'a']--;
    }
    for(int i=0;i<len1;i++){
        if(str1[s[i]-'a']!=0){
		return false;
	}
    }
    return true;
}
