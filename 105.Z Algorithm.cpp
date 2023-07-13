vector<int> calculateZ(string s){
    int n = s.length();
    vector<int> z(n);

    int left = 0 ,right = 0;
    z[0] = 0;
    for(int k=1;k<n;k++){
        if(k>right){
            left = right = k;
            while(right<n and s[right]==s[right-left])  right++;
            z[k] = right-left;
            right--;
        }
        else{
            int k1 = k - left;
            if(z[k1]<right-k+1){
                z[k] = z[k1];
            }
            else{
                left = k;
                while(right<n and s[right]==s[right-left])  right++;
                z[k] = right-left;
                right--;
            }
        }
    }
    return z;
}
int zAlgorithm(string s, string p, int n, int m)
{
    // Write your code here
    string t = p + "$" + s;
    vector<int> z = calculateZ(t);
    int ans = 0;
    for(int i=0;i<t.length();i++){
        if(z[i]==m) ans++;
    }
    return ans;
}