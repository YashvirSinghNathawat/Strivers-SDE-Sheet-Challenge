#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
    // Write your code here.
    string ans = "1";
    for(int i=1;i<n;i++){
        int j = 0;
        int k = ans.length();
        string temp = "";
        while(j<k){
            int freq = 0;
            char ch = ans[j];
            while(j<k and ans[j]==ch)   {
                freq++;
                j++;
            }
            // cout << to_string(freq) << " " << ch << endl;
            temp = temp + to_string(freq) + ch;
            // cout << temp << endl;
        }
        ans = temp;
    }   
    return ans;
}