int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i=0,j=0,cnt=0,ans=0;

    while(j<n){
        if(arr[j]==0) {
            cnt++;
            while(cnt>k){
                if(arr[i]==0)   cnt--;
                i++;
            }
            
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}
