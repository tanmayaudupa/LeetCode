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
// URL: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Type: linked list
// Name: Tanmaya Udupa
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        
        ListNode* temp = head;
        
        while(temp!= NULL){
            len +=1;
            temp = temp->next;
        }
        
        ListNode* prev1 =NULL;
        ListNode* prev2 = NULL;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        int ek = len-k+1;
        int ti = 1;
        while(temp1!=NULL && ti < k ){
            prev1 = temp1;
            temp1 = temp1->next;
            ti+=1;
        }
        ti = 1;
        
        while(temp2!=NULL && ti<ek){
            prev2 = temp2;
            temp2 = temp2-> next;
            ti+=1;
        }
        // cout<<temp1->val<<temp2->val<<prev2->val;
        ListNode* temp2t = temp2->next;
        ListNode* temp1t = temp1->next;
        if(prev1 !=NULL){
            prev1->next = temp2;
        }
        else{
            head = temp2;
        }
        
        if(temp2==temp1t){
            temp2->next = temp1;
        }
        else{
            temp2->next = temp1t;    
        }
        if(prev2 !=NULL){
            prev2->next = temp1;    
        }
        else{
            head = temp1;
        }
        
        if(temp1==temp2t){
            temp1->next = temp2;
        }
        else{
            temp1->next = temp2t;    
        }        
        
        return head;
    }
};