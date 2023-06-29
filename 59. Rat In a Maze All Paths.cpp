#include <bits/stdc++.h> 
void solve(int i,int j,int n,vector<vector<int>> &maze,vector<vector<int>> &ans){
  if(i==n-1 and j==n-1){
    vector<int> temp;
    for(auto l:maze){
      for(auto el:l){
        if(el==-1)    temp.push_back(1);
        else  temp.push_back(0);
      }
    }
    ans.push_back(temp);
    return;
  }
  //Downward
  if(i+1<n and maze[i+1][j]==1){
    maze[i+1][j]=-1;
    solve(i+1,j,n,maze,ans);
    maze[i+1][j]=1;
  }
  //Upward
  if(i-1>=0 and maze[i-1][j]==1){
    maze[i-1][j]=-1;
    solve(i-1,j,n,maze,ans);
    maze[i-1][j]=1;
  }
  //Left
  if(j-1>=0 and maze[i][j-1]==1){
    maze[i][j-1]=-1;
    solve(i,j-1,n,maze,ans);
    maze[i][j-1]=1;
  }
  //Right
  if(j+1<n and maze[i][j+1]==1){
    maze[i][j+1]=-1;
    solve(i,j+1,n,maze,ans);
    maze[i][j+1]=1;
  }
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n) {
  // Write your code here.
  vector<vector<int>> ans;
  if(maze[0][0]==0) return  {};
  maze[0][0]=-1;
  solve(0,0,n,maze,ans);
  return ans;
}