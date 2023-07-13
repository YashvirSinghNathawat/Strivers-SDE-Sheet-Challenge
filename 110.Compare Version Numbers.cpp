#include <bits/stdc++.h>
string removeBegin(string a){
    int p = a.length();

    for(int i=a.length()-1;i>=1;i-=2){
        if(a[i]=='0' and a[i-1]=='.'){
            p-=2;
        }
        else    break;
    }
    return a.substr(0,p);
} 
int compareVersions(string a, string b) 
{
    // Write your code here
    a = removeBegin(a);
    b = removeBegin(b);
    
    int i=0,j=0;
    int n = a.length();
    int m = b.length();
    while(true){
        int starta = i;
        int startb = j;
        while(i<n and a[i]!='.')        i++;
        while(j<m and b[j]!='.')        j++;
        if(i>j) return 1;
        if(i<j) return -1;

        for(int k=starta;k<i;k++){
            if(a[k]>b[k])   return 1;
            else if(a[k]<b[k])  return -1;
        }
        if(i==n and j==m)   return 0;
        if(i==n)    return -1;
        if(j==m)    return 1;   
        i++;
        j++;     
    }

    return 0;    
}