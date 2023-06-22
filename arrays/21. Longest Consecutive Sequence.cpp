#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];


int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int ans = 0;
    unordered_set<int> st;
    for(auto el:arr){
        st.insert(el);
    }
    for(int i=0;i<n;i++){
        if(st.find(arr[i]-1)==st.end()){
            int x = arr[i];
            int cnt = 0;
            while(st.find(x)!=st.end()){
                x++;
                cnt++;
            }
            if(cnt>ans) ans = cnt;
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
    cout << lengthOfLongestConsecutiveSequence(arr,n);
    return 0;
}