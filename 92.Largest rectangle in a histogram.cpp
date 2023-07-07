 #include<bits/stdc++.h>
 int largestRectangle(vector < int > & arr) {
   // Write your code here.
   stack<int> st;
   int ans = 0,n = arr.size();
   
   for(int i=0;i<=n;i++){
     while(!st.empty() and (i==n || arr[st.top()]>arr[i])){
       int height = arr[st.top()];
       st.pop();
       int width = st.empty()?i:i-st.top()-1;
       
       ans = max(ans,height*width);
     }
     st.push(i);
   }

   return ans;
 }