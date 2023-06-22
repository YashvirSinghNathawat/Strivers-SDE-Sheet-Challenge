#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int low = j+1;
            int high = n-1;
            int rem = target - arr[i] - arr[j];
            while(low<high){
                int mid = (low + high)/2;
                if(arr[low]+arr[high]==rem)  return "Yes";
                if(arr[low]+arr[high]<rem)   low++;
                else    high--;
            }
        }
    }
    return "No";
}

int main(){
    int n;
    cin >> n;
    int s;
    cin >> s;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    cout << fourSum(arr,s,n);
    return 0;
}