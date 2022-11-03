// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/binary-tree-pruning/
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
    
    bool pt(TreeNode* root){

        if ( !root->left && !root-> right && root->val == 1){
            return true;
        }
        bool ans1 = false;
        bool ans2 = false;
        if(root->left){
            ans1 = pt(root->left);
            if (!ans1){
                root->left = nullptr;
            }
        }
        
        if(root->right){
            ans2 = pt(root->right);
            if(!ans2){
                root->right = nullptr;
            }
        }
        
        if (ans1 || ans2 || root->val == 1){
            return true;
        }
        
        return false;
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        bool a = pt(root);
        if (!a){
            return NULL;
        }
        return root;
        
        
    }
};