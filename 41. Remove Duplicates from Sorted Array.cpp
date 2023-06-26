int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i=0,j=1;

	while(j<n){
		if(arr[j]>arr[i]){
			i++;
			arr[i]=arr[j];
			j++;
		}
		else	j++;
	}
	return i+1;
}