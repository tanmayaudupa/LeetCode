// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Type: Trees
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,vector<int>> map;
    
    
    void levelTraversal(TreeNode* root,int level){
        
        if (root == NULL){
            return;
        }
        
        map[level].push_back(root->val);
        levelTraversal(root->left,level+1);
        levelTraversal(root->right, level+1);
        
        
        return;
    }
    int maxLevelSum(TreeNode* root) {
        
        levelTraversal(root,1);
        
        int result = 0;
        int res = INT_MIN;
        
        for(auto i : map){
            int temp = accumulate(i.second.begin(), i.second.end(), 0);
            
            if (temp > res){
                result = i.first;
                res = temp;
            }
           
        }
                         
        return result;
        
    }
};