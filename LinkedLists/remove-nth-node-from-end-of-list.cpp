// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr = head;
        ListNode *now = head;
        for(int i=0;i<n;i++){
            ptr=ptr->next;
        }
        if(ptr==NULL){
            head = head->next;
            return head;
        }
        if(ptr!=NULL){
            while(ptr->next!=NULL){
                ptr = ptr->next;
                now = now->next;
            }
        }
        if(now->next == NULL){
            head = NULL;
        }
        else{
            now->next = now->next->next;
        }
        return head;
    }
};