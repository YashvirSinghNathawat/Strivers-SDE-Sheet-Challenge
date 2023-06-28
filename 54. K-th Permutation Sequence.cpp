string kthPermutation(int n, int k) {
    // Write your code here.
    int fact = 1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact = fact * i;
            nums.push_back(i);
        }
        nums.push_back(n);

        string ans = "";
        k = k-1;
        while(true){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            k = k%fact;
            if(nums.size()==0)  break;
            fact = fact / nums.size();
        }
        return ans;
}
