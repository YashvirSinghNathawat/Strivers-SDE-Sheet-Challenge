#include <bits/stdc++.h> 
bool canPlace(vector<int> &positions,int n,int c,int minD){
    int cor = positions[0] , cnt=1;

    for(int i=1;i<n;i++){
          if ((positions[i] - cor) >= minD) {
            cnt++;
            cor = positions[i];
        }
                if(cnt==c)  return true;
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
    // Write your code here
    sort(positions.begin(),positions.end());
    int low = 1 , high = positions[n-1] - positions[0];

    while(low<=high){
        int mid = (low+high)/2;

        if(canPlace(positions,n,c,mid)){
            low = mid + 1;
        }
        else    high = mid -1;
    }

    return high;
}