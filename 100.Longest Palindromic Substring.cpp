string longestPalinSubstring(string str)
{
    // Write your code here.
    int n = str.length();
    string ans = "";
    for(int i=0;i<n;i++){
        //For Odd
        int l=i-1,r=i+1,cnt=1;
        while(l>=0 and r<n and str[l]==str[r]) {
            cnt+=2;
            l--;
            r++;
        }
        if(ans.length()<cnt)        ans = str.substr(l+1,r-l-1);
        //For Even
        if(i==n-1)  break;
        l = i;
        r= i+1;
        cnt=0;
        while(l>=0 and r<n and str[l]==str[r])  {
            cnt+=2;
            l--;
            r++;
        }
        if(ans.length()<cnt)       ans = str.substr(l+1,r-l-1);
    }
    return ans;
}