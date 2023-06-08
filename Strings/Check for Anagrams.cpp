#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int mp[26]={0};
    int n = str1.length();
    if(n!= str2.length())  return false;

    for(int i=0;i<n;i++){

        mp[str1[i] - 'a']++;
        mp[str2[i] - 'a']--;
    }

    for(int i=0;i<26;i++){
        if(mp[i]>0)  return  false;
    }
    return true;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << areAnagram(s1,s2);
    return 0;
}