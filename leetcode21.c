/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* cur1=l1;
    struct ListNode* cur2=l2;
    struct ListNode* selected=NULL;
    struct ListNode* newLN=NULL;
    struct ListNode* newLN_cur=NULL;
    if(l1&&l2){
        if(l1->val<l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }else{
             l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    else if(l1){
        return l1;
    }else{
        return l2;
    }
}
