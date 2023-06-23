#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

void merge(vector<int> &arr,int n,int l,int mid,int h){
    int left = l;
    int right = mid + 1;
    vector<int> ans;
    while(left<=mid and right<=h){
        if(arr[left]<=arr[right]){
            ans.push_back(arr[left]);
            left++;
        }
        else{
            ans.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        ans.push_back(arr[left]);
        left++;
    }
    while(right<=h){
        ans.push_back(arr[right]);
        right++;
    }
    for(int i=l;i<=h;i++){
        arr[i] = ans[i-l];
    }
}
int countReverse(vector<int> &arr,int l,int mid,int h){
    int right = mid + 1;
    int cnt = 0;
    for(int i=l;i<=mid;i++){
        while(right<=h and arr[i]>2*arr[right]) right++;
        cnt+=right-(mid+1);
    }
    return cnt;
}
void mergeSort(vector<int> &arr,int n,int l,int h,int &cnt){
    if(l==h)    return;
    int mid = (l+h)>>1;
    mergeSort(arr,n,l,mid,cnt);
    mergeSort(arr,n,mid+1,h,cnt);
    cnt+=countReverse(arr,l,mid,h);
    merge(arr,n,l,mid,h);
}
int reversePairs(vector<int> &arr, int n){
    // Write your code here.    
    int cnt = 0;
    mergeSort(arr,n,0,n-1,cnt);
    return cnt;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << reversePairs(arr,n) << endl;
    for(auto el:arr)    cout << el << " ";
    return 0;
}