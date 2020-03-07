#define  Hash_SIZE 20001
#define OFFSET 10000//对下标为负数进行偏移使数组下标>=0

typedef struct{
    int val;
    int cnt;
}HashTable;

HashTable hash[Hash_SIZE];
int cmp(const void *a, const void *b) {
    return (((HashTable *)a)->cnt-((HashTable *)b)->cnt);
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    memset(hash,0,sizeof(hash));
    int i,j=0;
    for(i=0;i<numsSize;i++){
        hash[(nums[i]+OFFSET)%Hash_SIZE].cnt++;
        hash[(nums[i]+OFFSET)%Hash_SIZE].val=nums[i];
    }
    for(i=0;i<Hash_SIZE;i++){
        if(hash[i].cnt!=0){
            hash[j].cnt=hash[i].cnt;
            hash[j].val=hash[i].val;
            j++;
        }
    }
    //对hash表中的cnt进行快速排序，出现次数少的在前面，次数多的在后面
    qsort(hash,j,sizeof(HashTable),cmp);
    for(i=0;i<k;i++){
        nums[i]=hash[j-i-1].val;
    }
    *returnSize=k;
    return nums;
}
