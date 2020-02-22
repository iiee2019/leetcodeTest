/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(head==NULL||head->next==NULL||head->next->next==NULL){
        return head;
    }
    struct ListNode* newLN1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newLN2=(struct ListNode*)malloc(sizeof(struct ListNode));
    newLN1->val=0;
    newLN1->next=NULL;
    newLN2->val=0;
    newLN2->next=NULL;
    struct ListNode* p1=newLN1;
    struct ListNode* p2=newLN2;
    struct ListNode* p=head;
    for(int i=0;p;i++){
        if(i%2==0){
            p1->next=p;
            p=p->next;
            p1=p1->next;
            p1->next=NULL;
        }else{
            p2->next=p;
            p=p->next;
            p2=p2->next;
            p2->next=NULL;
        }
    }
    p1->next=newLN2->next;
    struct ListNode* ret = newLN1->next;
    return ret;
}
