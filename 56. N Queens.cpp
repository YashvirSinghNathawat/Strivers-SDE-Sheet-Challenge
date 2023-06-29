void solve(int col,int n,vector<vector<int>>& board,vector<vector<int>>& ans,vector<int> &leftRow,vector<int> &lowerD,vector<int> &upperD){
    if(col==n){
        vector<int> temp;
        for(auto list:board){
            for(auto el:list){
                temp.push_back(el);
            }
        }
        ans.push_back(temp);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftRow[row]==0 and lowerD[row+col]==0 and upperD[n-1+col-row]==0){
            board[row][col] =1 ;
            leftRow[row] = 1;
            lowerD[row+col] = 1;
            upperD[n-1+col-row] = 1;
            solve(col+1,n,board,ans,leftRow,lowerD,upperD);
            leftRow[row] = 0;
            lowerD[row+col] = 0;
            upperD[n-1+col-row] = 0;
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> board(n,vector<int> (n,0));
    vector<int> leftRow(n,0);
    vector<int> lowerD(2*n-1,0);
    vector<int> upperD(2*n-1,0);
    vector<vector<int>> ans;

    solve(0,n,board,ans,leftRow,lowerD,upperD);
    return ans;
}