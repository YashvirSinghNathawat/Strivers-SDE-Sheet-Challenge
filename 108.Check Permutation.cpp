#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    vector<int> alp(26,0);

    for(char ch:str1){
        alp[ch-'a']++;
    }
    for(char ch:str2){
        alp[ch-'a']--;
    }

    for(int i=0;i<26;i++){
        if(alp[i]!=0)   return false;
    }
    return true;

}