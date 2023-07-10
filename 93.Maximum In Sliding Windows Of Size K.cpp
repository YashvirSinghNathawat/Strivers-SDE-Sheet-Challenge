vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    deque<int> dq;
    vector<int> ans;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(!dq.empty() and dq.front()==i-k)     dq.pop_front();

        while(!dq.empty() and nums[i]>=nums[dq.back()]) dq.pop_back();
        dq.push_back(i);

        if(i>=k-1)      ans.push_back(nums[dq.front()]);
    }
    return ans;
}