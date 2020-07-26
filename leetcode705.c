#define HASH_FUNC 997
typedef struct MyLinkNode{
    int val;
    struct MyLinkNode* next;
} MyLinkNode;
typedef struct {
    int key;
    int count;
    MyLinkNode* ptr;
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet* obj=(MyHashSet*)malloc(HASH_FUNC*sizeof(MyHashSet));
    if(obj==NULL){
        return NULL;
    }
    for(int i=0;i<HASH_FUNC;i++){
        obj[i].key=i;
        obj[i].count=0;
        obj[i].ptr=NULL;
    }
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if(obj==NULL){
      return ;
    }
    int keyAfter=key%HASH_FUNC;
    if(obj[keyAfter].count==0){
        MyLinkNode* node=(MyLinkNode*)malloc(sizeof(MyLinkNode));
        node->next=NULL;
        node->val=key;
        obj[keyAfter].ptr=node;
        obj[keyAfter].count++;
    }else{
        MyLinkNode *tmp = obj[keyAfter].ptr;
        MyLinkNode *prev = tmp;
        while(tmp!=NULL){
            prev=tmp;
            if(tmp->val==key){
                break;
            }
            tmp=tmp->next;
        }
        if (tmp == NULL) { // 没有当前key的重复值，则加入
            MyLinkNode *node = (MyLinkNode *)malloc(sizeof(MyLinkNode));
            node->next = NULL;
            node->val = key;
            prev->next = node;
            obj[keyAfter].count++; // 记录该桶内 元素的 数量
        }
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if(obj==NULL){
      return ;
    }
    int keyAfter=key%HASH_FUNC;
    if (obj[keyAfter].count != 0) {
        MyLinkNode *tmp = obj[keyAfter].ptr;
        if (tmp->val == key) {  // 第一个node
            obj[keyAfter].ptr = tmp->next;
            free(tmp);  // 记得释放
            tmp = NULL;
            obj[keyAfter].count--;
        } else {
            while (tmp->next != NULL) {
                if (tmp->next->val == key) { // 找到了该 键-值的前驱
                    MyLinkNode *cur = tmp->next; // 为了释放
                    tmp->next = tmp->next->next;
                    free(cur);
                    cur == NULL;
                    obj[keyAfter].count--;
                    break;
                }
                tmp = tmp->next;
            }
        }
    }
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    if(obj==NULL){
      return ;
    }
    int keyAfter=key%HASH_FUNC;
    if(obj[keyAfter].count==0){
        return false;
    }
    MyLinkNode *tmp = obj[keyAfter].ptr;
    while(tmp!=NULL){
        if(tmp->val==key){
            return true;
        }
        tmp=tmp->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    if(obj==NULL){
      return ;
    }
    free(obj);
    obj=NULL;
}
