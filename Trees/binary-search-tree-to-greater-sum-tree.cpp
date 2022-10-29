// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root;
        }
        void inorder(TreeNode* root){
            if(root==NULL){
                return;
            }
            inorder(root->right);
            root->val = root->val + sum;
            sum = root->val;
            inorder(root->left);
        }
};