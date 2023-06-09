#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
vector<int> nextPermutation(vector<int> &arr, int n)
{
    //  Write your code here.
    int i=n-2;
    while(i>=0){
        if(arr[i]<arr[i+1]){
            break;
        }
        i--;
    }
    if(i==-1) {
        reverse(arr.begin(),arr.end());
        return arr;
    }
    int j;
    for(j=n-1;j>i;j--){
        if(arr[j]>arr[i]) break;
    }
    swap(arr[j],arr[i]);
    reverse(arr.begin()+i+1,arr.end());
    return arr;
}int main(){
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    vector<int> ans = nextPermutation(p,n);
    for(auto el:ans)  cout << el << " ";
    return 0;
}