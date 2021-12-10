/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *slow, *fast;
    slow = fast = head;
    int i = 0;
    
    while(i++ < n)
        fast = fast->next;
    
    if(!fast) {
        slow = head;
        head = head->next;
        free(slow);
        return head;
    }
    
    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    
    fast = slow->next;
    slow->next = slow->next->next;
    free(fast);
    return head;
}
