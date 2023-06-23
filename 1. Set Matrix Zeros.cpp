#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int c1 = 1;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        if(matrix[i][0]==0)  c1 = 0;
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>0;j--){
            if(matrix[i][0]==0 or matrix[0][j]==0)  matrix[i][j] = 0;
        }
        if(c1 == 0)   matrix[i][0] = 0;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > matrix(n,vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)  cin >> matrix[i][j];
    }
    setZeros(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)  cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}