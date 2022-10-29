// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/balance-a-binary-search-tree/
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
    vector<int> result;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        TreeNode* res = arr_bst(result,0,result.size()-1);
        return res;
    }
    TreeNode* arr_bst(vector<int>& nums,int low,int high){
        if ( low==high){
            return new TreeNode(nums[low]);
        }
        if(low>high){
            return NULL;
        }
        int mid = (low+high+1)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = arr_bst(nums,low,mid-1);
        root->right = arr_bst(nums,mid+1,high);
        return root;
        
    }
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
        return;
    }
};
