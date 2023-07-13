#include<bits/stdc++.h>

int minCharsforPalindrome(string str) {
    // Write your code here.
    int res = 0 , l = 0 , n = str.length() , r = n-1;

    while(l<r){
        if(str[l]==str[r]){
            l++;
            r--;
        }
        else{
            res++;
            l = 0;
            r = n - res - 1;
        }
    }
    return res;
}
