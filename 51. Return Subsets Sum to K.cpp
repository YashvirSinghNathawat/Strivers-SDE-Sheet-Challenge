void helper(int i,int n,int target,vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans){
        if(i==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(arr[i]);
        helper(i+1,n,target-arr[i],arr,ds,ans);
        ds.pop_back();
        helper(i+1,n,target,arr,ds,ans);
    }
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> ds;
        // sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        helper(0,arr.size(),k,arr,ds,ans);
        return ans;
}