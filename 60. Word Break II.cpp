#include <bits/stdc++.h> 
void solve(int ind,int n,string &s,string t,vector<string> &dictionary,vector<string> &ans){
    if(ind==s.length()){
        ans.push_back(t);
        return;
    }
    for(string w:dictionary){
        if(n-ind>=w.length() and s.substr(ind,w.length())==w){
            string temp = ((t=="")?(w):(t+" "+ w));
            solve(ind+w.length(),n,s,temp,dictionary,ans);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    unordered_set<string> st;
    for(auto str:dictionary)    st.insert(str);
    vector<string> dict;
    for(auto el:st)     dict.push_back(el);
    string t = "";
    solve(0,s.length(),s,t,dict,ans);
    return ans;

}