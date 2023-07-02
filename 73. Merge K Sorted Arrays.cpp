#include <bits/stdc++.h>
typedef pair<int,int> pii; 
vector<int> mergeKSortedArrays(vector<vector<int>>&a, int k)
{
    // Write your code here.
    vector<int> idx(k,0);
    vector<int> ans;
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    for(int i=0;i<k;i++){
        pq.push({a[i][0],i});
    } 
    while(!pq.empty()){
        pii x = pq.top();
        pq.pop();

        int arr_no = x.second;
        int value = x.first;
        int index = idx[arr_no];

        if(index+1<a[arr_no].size()){
            pq.push({a[arr_no][index+1],arr_no});
        }
        idx[arr_no]+=1;
        ans.push_back(value);
    }
    return ans;
}
