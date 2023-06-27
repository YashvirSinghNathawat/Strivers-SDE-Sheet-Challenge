#include <bits/stdc++.h> 

bool comparator(vector<int> a,vector<int>   b){
    return a[1]>=b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int maxDeadline = 0;
    int n = jobs.size();
    for(int i=0;i<n;i++){
        maxDeadline = max(maxDeadline,jobs[i][0]);
    }
    vector<int> deadline(maxDeadline+1,-1);
    sort(jobs.begin(),jobs.end(),comparator);
    int max_profit = 0;
    for(int i=0;i<n;i++){
        int d = jobs[i][0];
        while(d>=1){
            if(deadline[d]==-1){
                deadline[d] = 1;
                max_profit += jobs[i][1];
                break;
            }
            
            d--;
        }
    }
    return max_profit;
}
