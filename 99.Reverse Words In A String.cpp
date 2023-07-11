string reverseString(string &str){
    // Write your code here.
    vector<string> v;
    int n = str.length();
    string s="";
    for(int i=0;i<n;i++){
        if(str[i]==' '){
            if(s.length()==0)       continue;
            v.push_back(s);
            s="";
        }
        else s+=str[i];
    }   
    if(s!="")       v.push_back(s);
    reverse(v.begin(),v.end());
    string ans="";
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1){
            ans+=v[i];
        }   
        else{
            ans+=v[i] + " ";
        }
    }
    return ans;
}