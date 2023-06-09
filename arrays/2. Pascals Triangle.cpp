#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
long long fact[100005];
#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int> > ans;
  ans.push_back({1});
  if(n==1)  return ans;
  ans.push_back({1,1});
  if(n==2)  return ans;
  for(int i=2;i<n;i++){
    vector<long long int> temp;
    temp.push_back(1);

    for(int j=1;j<i;j++){
      temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
    }

    temp.push_back(1);
    ans.push_back(temp);
  }

  return ans;
}
int main(){
    int n;
    cin >> n;

    vector<vector<long long int>> ans = printPascal(n);
    for(auto list:ans){
        for(auto el:list) cout << el << " ";
        cout << endl;
    }
    return 0;
}