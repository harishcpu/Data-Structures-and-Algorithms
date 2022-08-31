/* 
Problem Statement:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = NULL;
        ListNode* temp = NULL, temp1 = NULL;
        
        int iter = 0;
        while(l1 || l2) {
            if(iter == 0)
                temp = new ListNode();
            else {
                temp->next = new ListNode();
                temp = temp->next;
            }
            
            if(iter++ == 0)   res = temp;
            
            temp->val = ((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            
            if(l1->next) {
                l1 = l1->next;
            } else {
                l1->val = 0;
                if(l2->val == 0 && l2->next == NULL)
                    break;
            }
            if(l2->next) {
                l2 = l2->next;
            } else {
                l2->val = 0;
                if(l1->val == 0 && l1->next == NULL)
                    break;
            }
        }
        if(carry) {
            temp->next = new ListNode();
            temp->next->val = carry;
        }
        return res;
    }
};
