int romanToInt(string s) {
    // Write your code here
    int ans = 0;
    map<char,int> m = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int n = s.length();
    for(int i=0;i<n;i++){
        int d = m[s[i]];
        if(i!=n-1 and m[s[i]]<m[s[i+1]])        d*=-1;
        ans = ans + d;
    }
    return ans;
}