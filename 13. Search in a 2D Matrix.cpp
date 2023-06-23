#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

bool searchMatrix(vector<vector<int>>& mat, int t) {
    //Identify row
    int n = mat.size();
    int m = mat[0].size();
    int s = 0 , e = n-1;
    int row=-1;
    while(s<=e){
        int mid = (s + e)>>1;
        if(mat[mid][0]<=t){
            row = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    } 
    if(row==-1) return false;

    
    //Find element in column
    s = 0;
    e = m-1;
    while(s<=e){
        int mid = (s + e)>>1;
        if(mat[row][mid]==t){
            return true;
        }
        else if(mat[row][mid]>t)  e = mid - 1;
        else s = mid + 1;
    }
    return false;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    int t;
    cin >> t;
    cout << searchMatrix(mat,t);
    return 0;
}