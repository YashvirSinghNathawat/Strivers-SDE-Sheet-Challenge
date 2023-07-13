#include <bits/stdc++.h> 
vector<int> computeLps(string &s){
    int n = s.length();
    vector<int> lps(n);
    lps[0] = 0;
    int i=0,j=1;

    while(j<n){
        if(s[i]==s[j]){
            lps[j] = i+1;
            i++;
            j++;
        }
        else{
            if(i==0)    j++;
            else    i = lps[i-1];
        }
    }
    return lps;
}
bool findPattern(string pattern, string text)
{
    // Write your code here.
    vector<int> lps = computeLps(pattern);
    int n = text.length();
    int m = pattern.length();

    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j==0)    i++;
            else    j = lps[j-1];
        }
        if(j==m){
            return true;
            j=lps[j-1];
        }
    }
    return false;
}