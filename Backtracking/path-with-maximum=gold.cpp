// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/path-with-maximum-gold/
// Type: Backtracking
class Solution {
public:
    int result = 0;
    set<pair<int,int>> path;
    int rows;
    int cols;
    int dfs(int r, int c, vector<vector<int>>& grid, int s){

    
        if(r>=rows || r<0 || c<0 || c>=cols || grid[r][c] <= 0){
            return max(s,result);
        }
        int temp = grid[r][c];
        grid[r][c] = -grid[r][c];
        int res1 = dfs(r+1,c,grid,s+temp);
        int res2 = dfs(r-1,c,grid,s+temp);
        int res3 = dfs(r,c+1,grid,s+temp);
        int res4 = dfs(r,c-1,grid,s+temp);
        grid[r][c] = -grid[r][c];

        return max(res1,max(res2,max(res3,res4)));


    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        rows = grid.size();
        cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if (grid[i][j]!=0){
                    result = max(result, dfs(i,j,grid,0));
                }
            }
        }

        return result;
    }
};
