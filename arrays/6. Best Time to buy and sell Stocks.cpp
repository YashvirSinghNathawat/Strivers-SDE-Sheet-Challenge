#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int maximumProfit(vector<int> &prices){
   
   stack<int> st;
   int ans = 0,minEl=prices[0];
   for(int i=0;i<prices.size();i++){
    if(ans<(prices[i]-minEl)){
        ans = prices[i]-minEl;
    }
    if(prices[i]<minEl) minEl = prices[i];
   }
   return ans;
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i=0;i<n;i++) cin >> p[i];
        cout << maximumProfit(p) << endl;
    }
    return 0;
}