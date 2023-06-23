#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort012(int *arr, int n)
{
   //   Write your code here
    int i = -1,j=0,k=n-1;
    while(j<=k){
        // cout << i << " " << j << " " << k << endl;
        if(arr[j]==0){
            i++;
            swap(&arr[i],&arr[j]);
            j++;
        }
        else if(arr[j]==2){
            swap(&arr[j],&arr[k]);
            k--;
        }
        else  j++;
    }
   
}
int main(){
    int n;
    cin >> n;

    int p[n];
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    sort012(p,n);
    for(int i=0;i<n;i++) cout << p[i] << " ";
    return 0;
}