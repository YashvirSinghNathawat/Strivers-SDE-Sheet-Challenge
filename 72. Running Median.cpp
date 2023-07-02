
#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;

    for(int i=0;i<n;i++){
        small.push(arr[i]);

        //Check if small top element > large top element
        if(small.size() and large.size() and (small.top() > large.top())){
            large.push(small.top());
            small.pop();
        }

        // //Check if size of small - large>1
        // cout << small.size() << " " <<  large.size() << endl;
        if((int)(small.size() - large.size())>1){
            large.push(small.top());
            small.pop();
        }
        // cout << small.size() << " " <<  large.size() << endl;
        if(!large.empty() and (int)(large.size()-small.size())>1){
            small.push(large.top());
            large.pop();
        }
        // cout << small.size() << " " <<  large.size() << " ";
        if(large.size() > small.size()){
            cout << large.top() << " " ;
        }
        else if(small.size()>large.size()){
            cout << small.top() << " ";
        }
        else{
            cout << (small.top() + large.top())/2 << " ";
        }
    }
}