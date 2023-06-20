#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here 
    int s=n*(n+1)/2,ss=n*1ll*(n+1)*(2*n+1)/6;
    for(int i=0;i<n;i++){
        s-=arr[i];
        ss-=arr[i]*arr[i];
    }
    int miss = (ss/s + s )/2;
    int rep = (ss/s - s)/2;
    for(int i=0;i<n;i++){
        if(arr[i]==miss){
            return {rep,miss};
        }
    }
    return {miss,rep};
    
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>> arr[i];
    pair<int,int> ans = missingAndRepeating(arr,n);
    cout << ans.first << " " << ans.second <<  endl;
    return 0;
}