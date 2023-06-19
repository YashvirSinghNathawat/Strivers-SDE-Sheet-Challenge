#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    int s = intervals[0][0];
    int e = intervals[0][1];
    vector<vector<int>> ans;
    for(int i=1;i<n;i++){
        int cs = intervals[i][0];
        int ce = intervals[i][1];
        
        if(cs<=e){
            e = max(e,ce);
        }
        else{
            ans.push_back({s,e});
            s = cs;
            e = ce;
        }
    }
    ans.push_back({s,e});
    return ans;
}
int main(){
    int n,m;
    cin >> n;

    vector<vector<int>> matrix(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin >> matrix[i][0] >> matrix[i][1];
    }
    vector<vector<int>> ans = mergeIntervals(matrix);
    for(auto p:ans){
        cout << p[0] << " " << p[1] << endl;
    }
    return 0;
}