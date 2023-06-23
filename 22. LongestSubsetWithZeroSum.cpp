#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

int LongestSubsetWithZeroSum(vector < int > arr) {
    map<int,int> m;
    int n = arr.size();
    int sum = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0)   ans = max(ans,i+1);
        if(m.find(sum)!=m.end()){
            cout << i << " " << m[sum] << endl;
            ans = max(ans,i-m[sum]);
        }
        else{
            m[sum] = i;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << LongestSubsetWithZeroSum(arr);
    return 0;
}