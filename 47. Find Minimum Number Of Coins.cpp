#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> denominations = {1000,500,100,50,20,10,5,2,1};
    int cnt = 0;
    int i = 0;
    while(amount>0){
        while(amount<denominations[i]) i++;
        amount-=denominations[i];
        cnt++;
    }
    return cnt;
}
