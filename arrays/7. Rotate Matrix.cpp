#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Preq : Spiral Matrix
void rotateMatrix(vector<vector<int>> &a, int n, int m)
{
    // Write your code here
    int left = 0 , right = m-1;
    int top = 0 , bottom = n-1;

    while(top<bottom and left<right){
        int previous = a[top+1][left];
        for(int i=left;i<=right;i++){
            int current = a[top][i];
            a[top][i]=previous;
            previous = current;
        }
        top++;
        for(int i=top;i<=bottom;i++){
            int current = a[i][right];
            a[i][right]=previous;
            previous = current;
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
            int current = a[bottom][i];
            a[bottom][i]=previous;
            previous = current;
        }
        bottom--;
        }
        
        if(left<=right){
           for(int i=bottom;i>=top;i--){
            int current = a[i][left] ;
            a[i][left] =previous;
            previous = current;
        }
        left++; 
        } 
    }
    if(top<=bottom and left==right){
        int temp = a[top][left];
        for(int i=top;i<bottom;i++){
            a[i][left] = a[i+1][left]; 
        }
        a[bottom][left] = temp;
    }
    if(left<right and top==bottom){
        int temp = a[top][right];
        for(int i=right;i>left;i--){
            a[top][i]=a[top][i-1];
        }
        a[top][left] = temp;

    }

}
int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> matrix(n,vector<int>(m));
    int k=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matrix[i][j] = k++;
        }
    }
    rotateMatrix(matrix,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}