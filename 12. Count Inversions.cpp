#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

void merge(long long *arr,long long s,long long mid,long long e,long long &cnt){
    int left = s;
    int right = mid + 1;
    vector<long long> temp;
    while(left<=mid and right<=e){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            cnt += (mid-left+1);
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=e){
        temp.push_back(arr[right++]);
    }
    for(int i=s;i<=e;i++){
        arr[i] = temp[i-s];
    }
}
void mergeSort(long long *arr,long long s,long long e, long long &cnt){
    if(s==e)  return;
    int mid = (s+e)>>1;
    mergeSort(arr,s,mid,cnt);
    mergeSort(arr,mid+1,e,cnt);
    merge(arr,s,mid,e,cnt);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long cnt = 0;
    mergeSort(arr,0,n-1,cnt);
    return cnt;
}
int main(){
    int n;
    cin >> n;
    long long arr[n];
    for(int i=0;i<n;i++) cin>> arr[i];
    cout << getInversions(arr,n);
    return 0;
}