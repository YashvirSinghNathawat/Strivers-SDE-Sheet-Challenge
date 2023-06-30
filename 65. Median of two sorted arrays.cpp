double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n = a.size();
	int m = b.size();
	if(n>m)	return median(b,a);
	int len = n+m;
	int low = 0;
	int high = n;
	while(low<=high){
		int cut1 = (low+high)/2;
		int cut2 = (len+1)/2-cut1;

		int l1 = (cut1==0)?INT_MIN:a[cut1-1];
		int r1 = (cut1==n)?INT_MAX:a[cut1];
		int l2 = (cut2==0)?INT_MIN:b[cut2-1];
		int r2 = (cut2==m)?INT_MAX:b[cut2];

		if(l1<=r2 and l2<=r1){
			if(len&1)	return max(l1,l2);
			double ans = (max(l1,l2)+min(r1,r2))/2.0;; 
			return ans;
		}
		else if(l1>r2)		high = cut1-1;
		else		low = cut1 + 1;
	}
	return 0.0;
}