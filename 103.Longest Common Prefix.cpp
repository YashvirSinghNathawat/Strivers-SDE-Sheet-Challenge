string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";
    int sl=arr[0].size();
    for(int i=0;i<n;i++){
        if(arr[i].size()<sl)    sl = arr[i].size();
    }

    for(int index=0;index<sl;index++){
        char ch = arr[0][index];
        bool flag = true;
        for(int j=1;j<n;j++){
            if(arr[j][index]!=ch){
                flag = false;
                break;
            }
        }
        if(flag==true)      ans+=ch;
        else    break;
    }
    return ans;
}


