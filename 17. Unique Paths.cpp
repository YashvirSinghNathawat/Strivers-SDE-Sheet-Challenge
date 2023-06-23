#include <bits/stdc++.h> 
int helper(int n,int m,int x,int y,vector<vector<int>> &dp){
        if(n==x and m==y)   return 1;
        if(dp[x][y]!=-1)    return dp[x][y];
        if(x>n || y>m)  return 0;
        return dp[x][y] = helper(n,m,x+1,y,dp) + helper(n,m,x,y+1,dp);
    }
int uniquePaths(int a, int b) {
	// Write your code here.
	vector<vector<int>> dp(20,vector<int> (20,-1));
        return helper(a,b,1,1,dp);
        
}