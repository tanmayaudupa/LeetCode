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
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head;
        if (head ==NULL){
            return NULL;
        }
        ListNode *nex = head->next;
        ListNode *prev = NULL;
        while(nex!=NULL){
            curr->next = nex->next;
            nex->next = curr;
            if (prev == NULL){
                head = nex;
            }   
            else{
                prev->next = nex;
            }
            prev = curr;
            curr = curr->next;
            if(curr !=NULL){
                nex = curr->next;
            }
            else{
                nex = NULL;
            }
        }
        return head;
    }
};