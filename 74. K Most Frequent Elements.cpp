#include <bits/stdc++.h>
typedef pair<int,int> pii ;
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++)    mp[arr[i]]++;

    priority_queue<pii,vector<pii>,greater<pii>> minH;

    for(auto it= mp.begin();it!=mp.end();it++){
        minH.push({it->second,it->first});
        if(minH.size()>k){
            minH.pop();
        }
    }
    while(!minH.empty()){
        ans.push_back(minH.top().second);
        minH.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}