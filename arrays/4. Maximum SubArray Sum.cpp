#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
long long maxSubarraySum(int arr[], int n)
{
    long long ans = 0,sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>ans)  ans = sum;
        if(sum<0)  sum=0;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;

    int p[n];
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    cout << maxSubarraySum(p,n);
    return 0;
}