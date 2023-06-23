#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];

int uniqueSubstrings(string arr)
{
    //Write your code here
    set<char> s;
    int ans = 0;
    int left = 0,right=0;
    int n = arr.length();
    while(right<n){
        if(s.find(arr[right])==s.end()){
            s.insert(arr[right]);
            right++;
        }
        else{
            while(left<=right and s.find(arr[right])!=s.end()){
                s.erase(arr[left]);
                left++;
            }
        }
        ans = max(ans,right-left);
    }
    return ans;
}
int main(){
    string s;
    cin >> s;

    cout << uniqueSubstrings(s);
    return 0;
}