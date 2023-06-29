bool isValid(int node,int c,vector<int> &col,vector<vector<int>> &mat,int n){
    for(int i=0;i<n;i++){
        if(i!=node and mat[node][i]==1 and col[i]==c)   return false;
    }
    return true;
}
bool solve(int node,vector<int> &col,vector<vector<int>> &mat,int m,int n){
    if(node==n){
        return true;
    }
    for(int i=0;i<m;i++){
        if(isValid(node,i,col,mat,n)){
            col[node] = i;
            if(solve(node+1,col,mat,m,n))   return true;
            col[node] = -1;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int> col(n,-1);
    if(solve(0,col,mat,m,n))    return "YES";
    return "NO";
}