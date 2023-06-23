#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int cnt1 = 0,el1=-1,el2=-1;
    int cnt2 = 0;

    int n = arr.size();
    for(int i=0;i<n;i++){
        if(cnt1==0 and el2!=arr[i]){
            el1 = arr[i];
        }
        else if(cnt2==0 and el1!=arr[i]){
            el2 = arr[i];
        }
        if(arr[i]==el1)   cnt1++;
        else if(arr[i]==el2)    cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==el1) cnt1++;
        if(arr[i]==el2) cnt2++;
    }
    vector<int> ans;
    if(cnt1>n/3) ans.push_back(el1);
    if(cnt2>n/3)    ans.push_back(el2);
    return ans;

}