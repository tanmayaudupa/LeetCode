// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/alphabet-board-path/
class Solution {
public:
    string alphabetBoardPath(string target) {
        int start_r = 0;
        int start_c = 0;
        int row;
        int col;
        string result;
        for(int i=0;i<target.length();i++){
            row = ((int)target[i]-97)/5;
            col = ((int)target[i]-97)%5;
            int r_diff = row - start_r;
            int c_diff = col - start_c;
            if(row==5){
                if(c_diff>0){
                    for(int j = 0;j<c_diff;j++){
                    result.push_back('R');
                    }
                }
                else if (c_diff<0){
                    for(int j = 0;j<abs(c_diff);j++){
                    result.push_back('L');
                    }
                }
                for(int j = 0;j<r_diff;j++){
                    result.push_back('D');
                    }
            }
            else {
            if(r_diff>0){
                for(int j = 0;j<r_diff;j++){
                    result.push_back('D');
                }
            }
            else if(r_diff<0){
                for(int j = 0;j<abs(r_diff);j++){
                    result.push_back('U');
                }
            }
            if(c_diff>0){
                for(int j = 0;j<c_diff;j++){
                    result.push_back('R');
                }
            }
            else if(c_diff<0){
                for(int j = 0;j<abs(c_diff);j++){
                    result.push_back('L');
                }
            }
            }
            result.push_back('!');
            start_r = row;
            start_c = col;
        }
        return result;
    }
};