/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val=0;
    dummy->next=head; //申请了一个虚拟节点
    struct ListNode *pNode=dummy;
    while(pNode->next&&pNode->next->next){
        struct ListNode* p1=pNode->next;
        struct ListNode* p2=p1->next;
        struct ListNode* nextLN=p2->next;
        pNode->next=p2;
        p2->next=p1;
        p1->next=nextLN;
        //pNode->next=p2;
        pNode=p1;
    }
    struct ListNode* retNode=dummy->next;
    free(dummy);
    return  retNode;
}
