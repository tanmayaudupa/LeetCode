// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/minimum-number-of-frogs-croaking/
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int maxf=0;
        int current = 0;
        int c=0,r=0,o=0,a=0,k = 0;
        for(int i=0;i<croakOfFrogs.size();i++){
            if(croakOfFrogs[i] == 'c'){
                c++;
                current++;
            }
            if(croakOfFrogs[i] == 'r'){
                r++;
            }
            else if(croakOfFrogs[i] == 'o'){
                o++;
            }
            else if(croakOfFrogs[i] == 'a'){
                a++;
            }
            else if(croakOfFrogs[i] == 'k'){
                k++;
                current--;
            }
            if(current>maxf){
                maxf = current;
            }
            if(c<r || r<o || o<a || a<k){
                return -1;
            }
        
        }
        if(c==r && c==o && c==a && c==k){
            return maxf;
        }
        else return -1;
    }
};