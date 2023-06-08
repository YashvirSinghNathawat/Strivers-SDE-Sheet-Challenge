#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

string longestCommonPrefix(vector<string> &arr, int n)
{
    string res = "";
    int j=0;
    while(true){
        char ch = arr[0][j];
        for(int i=1;i<n;i++){
            if(arr[i].length()==j or arr[i][j]!=ch){
                return res;
            }
        }
        res+=ch;
        j++;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << longestCommonPrefix(arr,n);
    return 0;
}