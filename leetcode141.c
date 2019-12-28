/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL)
         return false;
    struct ListNode *slow=head;
    struct ListNode *fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        if(slow->val==fast->val)
            return true;
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}
