// Author: Tanmaya Udupa
// URL: https://leetcode.com/problems/path-with-maximum-probability/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> umap;
        vector<double> table(n,2.0);
        table[start] = 0;
        vector<int> finished(n,0);
        table[start] = double(0);       
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;  
        pq.push(make_pair(0.0,start));
        
        for(int i=0;i<edges.size();i++){
            umap[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            umap[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        while(!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            if ( finished[node]==1){
                continue;
            }
            for(int i=0;i<umap[node].size();i++){
                    if(finished[umap[node][i].first]==0){
                        double tmp = min(table[umap[node][i].first],(1 - (1 - prob)*umap[node][i].second));  
                        if(table[umap[node][i].first]>tmp){
                            pq.push(make_pair(tmp,umap[node][i].first));
                            table[umap[node][i].first] = tmp;
                            path[umap[node][i].first] = node;
                        }
                }
            }
            finished[node]=1;
        }
        
        double result=0.0;
        result = table[end];
        if(1-result > 0)
            return 1-result;
        else
            return 0;
        }
       
};