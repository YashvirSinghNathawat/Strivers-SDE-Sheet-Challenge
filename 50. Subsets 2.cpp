#include <bits/stdc++.h> 
void helper(int i,int n,vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int k=i;k<n;k++){
            if(k>i and nums[k]==nums[k-1])  continue;
            temp.push_back(nums[k]);
            helper(k+1,n,nums,temp,ans);
            temp.pop_back();
        }
    }
vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
{
    // Write your code here.
    vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        helper(0,nums.size(),nums,temp,ans);
        return ans;
}