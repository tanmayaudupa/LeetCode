// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    int getMinimumDifference(TreeNode* root) {
        int mind = INT_MAX;
        int val = -1;
        mind = find_inorder(root,mind,val);
        return mind;
    }
    int find_inorder(TreeNode* root,int &mind,int& val){
        if(root==NULL){
            return mind;
        }
        find_inorder(root->left,mind,val);
        if(val>-1){
            mind = min(mind,root->val-val);
        }
        val = root->val;
        find_inorder(root->right,mind,val);
        return mind;
    }
};