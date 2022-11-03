// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/find-leaves-of-binary-tree/
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
    vector<vector<int>> result;
    vector<int> temp;
    
    TreeNode* calc(TreeNode* root){

        if (root->left == NULL and root->right == NULL){
            temp.push_back(root->val);
            return nullptr;
        }
        
        if(root->left){
            root->left = calc(root->left);
        }
        
        if (root->right){
            root->right = calc(root->right);
        }
        return root;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        while(root!=NULL){
            root = calc(root);
            result.push_back(temp);
            temp.clear();
        }
        
        return result;
        
    }
};