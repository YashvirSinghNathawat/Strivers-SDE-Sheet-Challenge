#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;

    vector<int> nse(n,-1);

    for(int i=0;i<n;i++){
        while(!s.empty() and arr[s.top()]>arr[i]){
            nse[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return nse;


}