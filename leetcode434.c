#include <ctype.h>

int countSegments(char * s){
    int len=strlen(s);
    char* ptr=s;
    int i;
    int cnt=0;
    for(i=0;i<len-1;i++){
        if(isspace(ptr[i])&&!isspace(ptr[i+1])){
            cnt++;
        }
    }
    if(cnt==len){
        return 0;
    }
    return ptr[0]==' '?cnt:cnt+1;
}
