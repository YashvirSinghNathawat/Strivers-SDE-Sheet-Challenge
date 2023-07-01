#include <bits/stdc++.h> 
int findStudent(vector<int> time,int n,long long maxPages){
    int st = 1;
    long long cpage = 0;
    for(int i=0;i<n;i++){
        if(time[i]+cpage<=maxPages) cpage += time[i];
        else    {
            st++;
            cpage = time[i];
        }
    }
    return st;
}
long long ayushGivesNinjatest(int m, int n, vector<int> time) 
{   
    // Write your code here.
    long long low=-1,high=0;
    for(int i=0;i<n;i++){
        if(time[i]>low) low = time[i];
        high += time[i];
    }
    while(low<=high){
        long long mid = (low+high)>>1;
        int sreq = findStudent(time,n,mid);
        if(sreq<=m)         high = mid - 1;
        else    low = mid+1;
    }
    return low;
}