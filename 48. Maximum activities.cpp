#include<bits/stdc++.h>
bool comparator(pair<int,int> a,pair<int,int> b){
    return a.second<=b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    
    int n = start.size();
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        arr[i] = {start[i],finish[i]};
    }
    sort(arr.begin(),arr.end(),comparator);
    int cnt = 0;
    int timer = -1;
    for(int i=0;i<n;i++){
        if(arr[i].first>=timer){
            timer = arr[i].second;
            cnt++;
        }
    }
    return cnt;
}