#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int i, int j){
    if(arr1[i]>arr2[j])  swap(&arr1[i],&arr2[j]);
}
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int n, int m) {
    // Write your code here.
    vector<int> ans;
    //Gap Method
    int len = n+m;
    int gap = len/2 + len%2;
    while(gap>0){
        int left = 0;
        int right = left + gap;

        while(right<len){

            if(left<n and right>=n){
                swapIfGreater(arr1,arr2,left,right-n);
            }
            else if(left>=n){
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            else{
                swapIfGreater(arr1,arr1,left,right);
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap = gap/2 + gap%2;
        
    }
    for(int i=0;i<n;i++)  ans.push_back(arr1[i]);
    for(int i=0;i<m;i++)  ans.push_back(arr2[i]);
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for(int i=0;i<n;i++) cin>> arr1[i];
    for(int i=0;i<m;i++) cin>> arr2[i];
    vector<int> ans = ninjaAndSortedArrays(arr1,arr2,n,m);
    for(auto p:ans){
        cout << p << " ";
    }
    return 0;
}