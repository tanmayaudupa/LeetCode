// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        if(head==NULL){
            return NULL;
        }
        ListNode *ptr = head;
        while(ptr!=NULL){
            ptr= ptr->next;
            len+=1;
        }
        int rotate = k%len;
        ListNode *pt = head;
        ListNode *now = head;
        for(int i=0;i<rotate;i++){
            pt=pt->next;
        }
        if(pt!=NULL){
            while(pt->next!=NULL){
                pt = pt->next;
                now = now->next;
            }
        }
        pt->next = head;
        head = now->next;
        now->next = NULL;
        return head;
    }
};