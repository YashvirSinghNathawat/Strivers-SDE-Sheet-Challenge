#include <bits/stdc++.h> 
bool comparator(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.second==b.first.second)  return a.second<=b.second;
    return a.first.second<=b.first.second;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<pair<pair<int,int>,int> > arr(n);
    for(int i=0;i<n;i++){
      arr[i] = {{start[i], end[i]}, i + 1};
    }
    sort(arr.begin(),arr.end(),comparator);
    int time = arr[0].first.second;
    vector<int> ans;
    ans.push_back(arr[0].second);
    for(int i=1;i<n;i++){
        if(arr[i].first.first>time){
            ans.push_back(arr[i].second);
            time = arr[i].first.second;
        }
    }
    // sort(ans.begin(),ans.end());
    return ans;
}