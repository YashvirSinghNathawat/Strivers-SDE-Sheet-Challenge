#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> arr, int n) {
    // Write your code here.
    vector<int> ans(n,INT_MIN);
    stack<int> st;
    for(int i=0;i<=n;i++){
        while(!st.empty() and (i==n || arr[st.top()]>arr[i])){
            int element = arr[st.top()];
            st.pop();
            int mws;
            if(st.empty())  mws = i;
            else    mws = i-st.top()-1;
            ans[mws-1] = max(ans[mws-1],element);
        }
        st.push(i);
    }
    int maxe = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(ans[i]>maxe) maxe = ans[i];
        else     ans[i] = maxe;
    }
    return ans;
}