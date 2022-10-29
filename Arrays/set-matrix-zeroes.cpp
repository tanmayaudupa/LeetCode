// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> umap;
        vector<pair<int,int>> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    v.push_back(make_pair(i,j));
                }
            }
        }
        for(auto i :v){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i.first][j]=0;
            }
            for(int j=0;j<matrix.size();j++){
                matrix[j][i.second]=0;
            }
        }
    }
};