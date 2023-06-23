#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
int findDuplicate(vector<int> &arr, int n){
    // Write your code here.
    int slow = arr[0];
    int fast = arr[0];
    while(true){
        slow = arr[slow];
        fast = arr[arr[fast]];
        if(slow==fast)  break;
    }
     slow = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>> arr[i];
    int ans = findDuplicate(arr,n);
    cout << ans << endl;
    return 0;
}