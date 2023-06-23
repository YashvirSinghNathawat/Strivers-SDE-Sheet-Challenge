#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int cxor = 0;
    int n = arr.size();
    map<int,int> m;
    m[0] = 1;
    int ans = 0;
    for(int i=0;i<n;i++){
        cxor = cxor^arr[i];
        // if(cxor==x)     ans+=1;
        int y = cxor^x;
        if(m.find(y)!=m.end()){
            ans+=m[y];
        } 
        m[cxor]++;
    }
    return ans;
}
int main(){
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << subarraysXor(arr,x);
    return 0;
}