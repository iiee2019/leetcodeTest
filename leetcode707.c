typedef struct MyLinkedList_t{
    struct MyLinkedList_t* next;
    int val;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->next=NULL;
    obj->val=0;
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index<0||obj->next==NULL){
        return -1;
    }
    MyLinkedList * cur=obj->next;
    int k=0;
    while(k<index){
        if(cur==NULL){
            return -1;
        }
        cur=cur->next;
        k++;
    }
    if(cur!=NULL){
        return cur->val;
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList * new = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    new->next=NULL;
    new->val=val;
    if(obj->next==NULL){
        obj->next=new;
        return ;
    }else{
        new->next=obj->next;
        obj->next=new;
    }
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList * new = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    new->next=NULL;
    new->val=val;
    MyLinkedList * cur=obj;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=new;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index<=0){
        myLinkedListAddAtHead(obj, val);
    }
    MyLinkedList * cur=obj->next;
    int k=0;
    while(cur->next!=NULL){
        if(k==index-1){
            break;
        }
        cur=cur->next;
        k++;
    }
    if(k>index){
        return ;
    }
    MyLinkedList * new = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    new->val=val;
    new->next=cur->next;
    cur->next=new;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index<0|| obj->next == NULL){
       return ;
    }
    if(index==0){
        obj->next=obj->next->next;
        return ;
    }
    MyLinkedList * cur=obj->next;
    int k=0;
    while(cur->next!=NULL){
        if(k==index-1){
            break;
        }
        cur=cur->next;
        k++;
    }
    if(k==index-1&&cur->next!=NULL){
        cur->next=cur->next->next;
    }
}
void myNodeFree(MyLinkedList* Node) {
    if(Node->next!=NULL){
        myNodeFree(Node->next);
        Node->next=NULL;
    }
    free(Node);
}
void myLinkedListFree(MyLinkedList* obj) {
    myNodeFree(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
