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
// URL: https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/
// Type: linked list
// Name: Tanmaya Udupa
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int> map;
        
        ListNode* temp=head;
        ListNode* prev = NULL;
        
        
        while(temp !=NULL){
            map[temp->val]+=1;
            temp = temp->next;
        }
        
        temp = head;
        while(temp !=NULL){
            
            if(map[temp->val]>1){
                // cout<<temp->val;
                if (prev!=NULL){
                prev->next = temp->next;    
                }
                else{
                    head = temp->next;
                }
                temp = temp->next;
            }
            else{
                prev = temp;
                temp = temp->next;    
            }
            
        }
        
        return head;
    }
};