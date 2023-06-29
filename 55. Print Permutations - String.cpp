#include <bits/stdc++.h> 
void helper(int ind,string &s,vector<string> &ans){
    if(ind==s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<s.length();i++){
        swap(s[ind],s[i]);
        helper(ind+1,s,ans);
        swap(s[ind],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    helper(0,s,ans);
    return ans;
}