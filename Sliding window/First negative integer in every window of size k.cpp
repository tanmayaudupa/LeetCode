// Author: Tanmaya Udupa
// URL: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
// GeeksforGeeks
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    long long int i=0;
    long long int j=0;
    long long int k=K;
    queue<long long int> next;
    vector<long long int> result;
    while(j<N){
        if(j-i+1<k){
            if(A[j]<0){
                next.push(A[j]);
            }
            j++;
        }
        else if((j-i+1)==k){
            if(A[j]<0){
                next.push(A[j]);
            }
            if(!next.empty()){
                result.push_back(next.front());
            }
            else{
                result.push_back(0);
                // cout<<i<<j<<endl;
            }
            if(A[i]==next.front()){
                next.pop();
            }
            i++;
            j++;
        }
    }
    return result;
    
 }