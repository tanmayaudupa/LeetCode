// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/add-two-numbers/
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
        ListNode *root = new ListNode();
        ListNode *temp = root;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0; 
        while(p1 !=NULL || p2!=NULL || carry){
            int sum =0;
            if (p1!=NULL){
                sum = sum + p1->val;
                p1 = p1->next;
            }
            if(p2!=NULL){
                sum = sum +p2->val;
                p2 = p2->next;
            }
            sum = sum + carry;
            carry=0;
            if (sum/10 ==1){
                sum = sum%10;
                carry=1;
            }
            ListNode *newNode = new ListNode(sum);
            temp->next = newNode;
            temp = temp->next;
        }
        return root->next;   
    }
};