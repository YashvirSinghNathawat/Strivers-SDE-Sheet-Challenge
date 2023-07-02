#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    // Write your code here.
    priority_queue<pair<int,pair<int,int>>> pq;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    set<pair<int,int>> s;

    vector<int> res;
    pq.push({a[n-1]+b[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});

    while(k>0){
        pair<int,pair<int,int>> p = pq.top();
        pq.pop();

        int sum = p.first;
        int x = p.second.first;
        int y = p.second.second;

        res.push_back(sum);
        if(s.find({x-1,y})==s.end()){
            pq.push({a[x-1]+b[y],{x-1,y}});
            s.insert({x-1,y});
        }

        if(s.find({x,y-1})==s.end()){
            pq.push({a[x]+b[y-1],{x,y-1}});
            s.insert({x,y-1});
        }
        k-=1;
    }
    return res;
}