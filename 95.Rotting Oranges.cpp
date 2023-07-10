#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pair<pair<int,int>,int>>   q;
    vector<vector<int>> visited(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
            else    visited[i][j] = 0;
        }
    }
    int tm=0;
    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tm = max(tm,t);

        for(int i=0;i<4;i++){
            int row = r + drow[i];
            int col = c + dcol[i];
            if(row>=0 and row<n and col>=0 and col<m and grid[row][col]==1 and visited[row][col]==0){
                q.push({{row,col},t+1});
                visited[row][col] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && visited[i][j]==0)       return -1;
        }
    }
    return tm;
}