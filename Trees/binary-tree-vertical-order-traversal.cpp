// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/binary-tree-vertical-order-traversal/
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
    map<int,map<int,vector<int>>> map;
    
    void calculate(TreeNode* root, int clevel, int rlevel){
        
        if (root == NULL){
            return;
        }
        
        
        map[clevel][rlevel].push_back(root->val);
        
        calculate(root->left,clevel-1,rlevel+1);
        calculate(root->right,clevel+1,rlevel+1);
        
        return;
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        calculate(root,0,0);
        vector<vector<int>> result;
        for(auto col : map) {
            vector<int> a;
            for(auto row : col.second) {
                for(auto x : row.second) {
                    a.push_back(x);
                }
            }
            result.push_back(a);
        }
        return result;
    }
};