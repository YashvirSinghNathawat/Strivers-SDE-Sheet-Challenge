#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	 n = arr.size();
	vector<vector<int>> ans;
	for(int i=0;i<n-2;i++){
		int s = i+1;
		int e = n-1;
		int rem = K - arr[i];
		while(s<e){
			if((arr[s]+arr[e])==rem){
				ans.push_back({arr[i],arr[s],arr[e]});
				s++;
				while(s<e and arr[s]==arr[s-1])	s++;
			}
			else if(arr[s]+arr[e]<rem)	{
				s++;
				while(s<e and arr[s]==arr[s-1])	s++;
			}
			else			{
				e--;
				while(s<e and arr[e]==arr[e+1])	e--;
			}
		}
		while(i<n-1 and arr[i]==arr[i+1])		i++;
	}
	return ans;
}