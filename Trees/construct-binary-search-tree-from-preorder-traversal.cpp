// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root = construct(preorder);
        return root;
    }
    TreeNode* construct(vector<int> order){
        vector<int> left;
        vector<int> right;
        if(order.size()==0){
            return NULL;
        }
        TreeNode* root = new TreeNode(order[0]);
        int i=1;
        while(i<order.size()){
            if(order[i]<=order[0]){
                left.push_back(order[i]);
            }
            else{
                right.push_back(order[i]);
            }
            i++;
        }
        root->left = construct(left);
        root->right = construct(right);
        return root;
        
    }
};