#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    sort(arr.begin(),arr.end());

    int kSmall = arr[k-1];
    int kLar = arr[n-k];
    return {kSmall,kLar};


}