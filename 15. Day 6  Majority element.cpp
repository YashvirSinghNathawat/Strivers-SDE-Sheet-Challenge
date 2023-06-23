#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int cnt=0,maj;
	for(int i=0;i<n;i++){
		if(cnt==0){
			maj = arr[i];
		}
		if(arr[i]==maj){
			cnt +=1;
		}
		else cnt-=1;
	}

	cnt = 0;
	for(int i=0;i<n;i++){
		if(arr[i]==maj)  cnt++;
	}
	if(cnt>(n/2))  return maj;
	return -1;
}