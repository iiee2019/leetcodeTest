/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head==NULL)
        return NULL;
	struct ListNode* first = head;
	struct ListNode* last = head;
    int count=n;
	while (count>0) {
        if(first->next){
            first = first->next;
        }else
            return head->next;
         count--;
	}
	while (first->next) {
		first = first->next;
		last = last->next;
	}
	struct ListNode *retNode = last->next;
	last->next = retNode->next;
	free(retNode);
	return head;
}
