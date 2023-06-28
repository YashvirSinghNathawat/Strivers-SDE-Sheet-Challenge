void helper(vector<int>& nums,int csum,vector<int> &ans,int i,int n){
	if(i==n){
		ans.push_back(csum);
		return;
	}
	helper(nums,csum,ans,i+1,n);
	helper(nums,csum+nums[i],ans,i+1,n);
}
vector<int> subsetSum(vector<int> &nums){
	// Write your code here.
	vector<int> ans;
	helper(nums,0,ans,0,nums.size());
	sort(ans.begin(),ans.end());
	return ans;	
}