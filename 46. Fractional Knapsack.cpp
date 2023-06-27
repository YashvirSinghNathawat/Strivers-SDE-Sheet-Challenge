#include <bits/stdc++.h> 
bool comparator(pair<int,int> a , pair<int,int> b){
    double r1 = a.second*1.0/a.first;
    double r2 = b.second*1.0/b.first;
    return r1>r2; 
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comparator);
    double ans = 0;
    for(int i=0;i<n;i++){
        if(items[i].first<=w){
            w-=items[i].first;
            ans+=items[i].second;
        }
        else if(w!=0){
            ans += (items[i].second*1.0/items[i].first)*1.0*w;
            break;
        }
    }
    return ans;
}