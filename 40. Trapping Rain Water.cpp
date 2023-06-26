#include <bits/stdc++.h> 
long getTrappedWater(long *a, int n){
    // Write your code here.
    long l = 0,r = n-1,lmax = 0 , rmax=0;
    long res = 0;

    while(l<r){
        if(a[l]<=a[r]){
            if(a[l]>=lmax)  lmax = a[l];
            else    res+=(lmax-a[l]);
            l++;
        }
        else{
            if(a[r]>=rmax)  rmax = a[r];
            else    res+=(rmax-a[r]);
            r--;
        }
    }
    return res;
}