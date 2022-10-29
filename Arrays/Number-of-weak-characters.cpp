// Type : Sorting/Greedy
// Name: Tanmaya Udupa
class Solution {
public:
    
    static bool comp (vector<int> & a, vector<int>&b){
        if (a[0]==b[0]){
            return a[1] > b[1];
        }
        
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        int result = 0;
        int maxd = properties[properties.size()-1][1];
        for (int i=properties.size()-2;i>=0;i--){
            if (properties[i][1] < maxd){
                result+=1;
            }
            else{
                maxd = properties[i][1];
            }
        }
        
        return result;
    }
};