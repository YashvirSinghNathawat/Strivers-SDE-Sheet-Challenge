#include<bits/stdc++.h>
void helper(int i,int n,int target,vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans){
            if(target==0){
                ans.push_back(ds);
                return;
            }
            
        for(int k=i;k<n;k++){
            if(k>i and arr[k]==arr[k-1])    continue;
            if(arr[k]>target)   break;
            ds.push_back(arr[k]);
            helper(k+1,n,target-arr[k],arr,ds,ans);
            ds.pop_back();
        }
    }
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<int> ds;
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    helper(0,arr.size(),target,arr,ds,ans);
    return ans;
}
