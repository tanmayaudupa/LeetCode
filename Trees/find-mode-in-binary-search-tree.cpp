// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    unordered_map<int,int> umap;
    vector<int> findMode(TreeNode* root) {
        // for(int i=0)
        find_inorder(root);
        vector<int> result;
        int res=0;
        for(auto i:umap){
            res = max(res,i.second);
        }
        for(auto i:umap){
            if(i.second==res){
                result.push_back(i.first);
            }
        }
        return result;
    }
    void find_inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        find_inorder(root->left);
        if(umap.find(root->val)==umap.end()){
            umap[root->val] = 0;
        }
        umap[root->val]+=1;
        find_inorder(root->right);
    }
};