#include <bits/stdc++.h>

int modularExponentiation(int a, int b, int m) {
	// Write your code here.
	int ans = 1;
	while(b){
		if(b&1)  ans = (a*1ll*ans)%m;
		a = (a*1ll*a)%m;
		b>>=1;
	}
	return ans;
}