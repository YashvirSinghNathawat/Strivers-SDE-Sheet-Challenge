#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int ans = 0;
    int n = str.length();
    for(int i=0;i<n;i++){
        if(str[i]>='0' and str[i]<='9'){
            ans = ans*10+(str[i]-'0');
        }
    }
    if(str[0]=='-')  ans*=-1;
    return ans;
}