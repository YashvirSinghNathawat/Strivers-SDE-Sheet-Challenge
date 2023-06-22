#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];


vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   map<int,int> mp;
   vector<vector<int>> ans;
   int n = arr.size();
   for(int i=0;i<n;i++){
      int first = arr[i];
      int second = s-arr[i];
      if(mp.find(second)!=mp.end()){
        int val = mp[second];
        if(first>second)   swap(first,second);
        while(val--)
          ans.push_back({first, second});
      }
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}
int main(){
    int n;
    cin >> n;
    int s;
    cin >> s;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    vector<vector<int>> ans = pairSum(arr,s);
    for(auto list:ans){
        for(auto el:list)   cout << el << " ";
        cout << endl;
    }
    return 0;
}