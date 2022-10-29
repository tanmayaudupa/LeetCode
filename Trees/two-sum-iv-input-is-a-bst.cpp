// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    set<int> s;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        bool result = find(root,k);
        return result;
        
    }
    bool find(TreeNode* root, int k){
        if(root==NULL){
            return 0;
        }
        int diff = k-root->val;
        if(root->val !=diff && s.find(diff)!=s.end()){
            return 1;
        }
        else{
            return (find(root->left,k)||find(root->right,k));
            }
    }
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        s.insert(root->val);
        inorder(root->right);
    }
};