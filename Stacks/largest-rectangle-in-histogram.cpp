//Author: Tanmaya Udupa
//URL: https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right;
        stack<pair<int,int>> s;
        stack<pair<int,int>> s1;
        vector<int> left;
        right.assign(heights.size(),0);
        left.assign(heights.size(),0);
        int j = 0;
        int k = 0;
        int flag=0;
        for(int i=heights.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(make_pair(heights[i],i));
                right[j] = heights.size();
                j++;
                continue;
            }
            while(heights[i]<=s.top().first){
                s.pop();
                if(s.empty()){
                    right[j] = heights.size();
                    s.push(make_pair(heights[i],i));
                    flag = 1;
                    break;                    
                }
            }      
            if(flag ==0){
                right[j] = s.top().second;
                s.push(make_pair(heights[i],i));
                j++;
            }
            else{
                flag=0;
                j++;
            }
        }
        reverse(right.begin(),right.end());
        cout<<endl;
        for(int i=0;i<heights.size();i++){
            if(s1.empty()){
                s1.push(make_pair(heights[i],i));
                left[k] = -1;
                k++;
                continue;
            }
            while(heights[i]<=s1.top().first){
                s1.pop();
                if(s1.empty()){
                    left[k] = -1;
                    s1.push(make_pair(heights[i],i));
                    flag=1;
                    break;                    
                }
            }        
            if(flag==0){
                left[k] = s1.top().second;
                s1.push(make_pair(heights[i],i));
                k++;
            }
            else{
                flag = 0;
                k++;
            }
        }
        vector<int> result;
        result.assign(heights.size(),0);
        int diff=0;
        for(int i=0;i<heights.size();i++){
            diff = right[i]-left[i]-1;
             result[i] = diff*heights[i];
        }
        int max = 0;
        for(int i=0;i<heights.size();i++){
            if(result[i]>max){
                max = result[i];
            }
        }
        
        return max;
    }
};