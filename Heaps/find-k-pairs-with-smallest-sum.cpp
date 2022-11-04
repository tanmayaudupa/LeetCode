// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
// Type: Heap (Max Heap)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i =0;
        int j = 0;

        priority_queue<pair<int,vector<int>>> pq;

        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                int sum = nums1[i]+nums2[j];
                if (pq.size()<k){
                    vector<int> temp;
                        temp.push_back(nums1[i]);
                        temp.push_back(nums2[j]);
                    pq.push(make_pair(sum,temp));
                }
                else{
                        vector<int> temp;
                        temp.push_back(nums1[i]);
                        temp.push_back(nums2[j]);
                        
                        if(sum > pq.top().first){
                            break;
                        }
                        else{
                            pq.push(make_pair(sum,temp));
                            pq.pop();
                        }
                    
                }
                
            }
        }

        vector<vector<int>> result;
        while(pq.size()>0){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};