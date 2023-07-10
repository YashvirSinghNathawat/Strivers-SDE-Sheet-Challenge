#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector<int> ans;
    int n = price.size();
    stack<int> st;
    for(int i=0;i<n;i++){

        while(!st.empty() and price[st.top()]<=price[i])    st.pop();

        ans.push_back(st.empty()?i+1:i-st.top());
        st.push(i);
    }
    return ans;
}