//Author: Tanmaya Udupa
//URL: https://leetcode.com/problems/remove-k-digits/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        s.push(num[0]-48);
        for(int i=1;i<num.length();i++){
            if (k<=0){
                s.push(num[i]-48);
            }
            else{
                if((num[i]-48)>s.top()){
                    s.push(num[i]-48);
                }
                else{
                while(!s.empty() && s.top()>(num[i]-48) && k>0 ){    
                    s.pop();
                    k--;
                }
                s.push(num[i]-48);
                }
            }
        }
        if(k>0){
            while(k!=0){
                s.pop();
                k--;
            }
        }
        string result;
        while(!s.empty()){
            result += to_string(s.top());
            s.pop();
        }
        reverse(result.begin(),result.end());
        int j=0;
        while((result[j]=='0')){
            j++;
        }
        result = result.substr(j,result.length()-j);
        if (result.length()==0){
            return "0";
        }
        return result;
    }
};