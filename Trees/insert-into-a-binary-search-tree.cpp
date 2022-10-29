// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * tmp = root;
        TreeNode * parent;
        if(root==NULL){
            return (root = new TreeNode(val));
        }
        while(tmp!=NULL){
            if(val>tmp->val){
                parent = tmp;
                tmp = tmp->right;
            }
            else{
                parent = tmp;
                tmp = tmp->left;
            }
            cout<<parent->val<<endl;
        }
        
        if(val<parent->val){
            parent->left = new TreeNode(val);
        }
        else{
            parent->right = new TreeNode(val);
        }
        return root;
    }
};