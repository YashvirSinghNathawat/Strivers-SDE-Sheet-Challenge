#include <bits/stdc++.h> 
 bool isPalindrome(string s,int st,int e){
        while(st<e){
            if(s[st]!=s[e]) return false;
            st++;
            e--;
        }
        return true;
    }
    void helper(int ind,int n,string s,vector<string> &ds,vector<vector<string>> &ans){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++){
            if(isPalindrome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                helper(i+1,n,s,ds,ans);
                ds.pop_back();
            }
        }
    }
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<string> ds;
        vector<vector<string>> ans;
        helper(0,s.length(),s,ds,ans);
        return ans;
}