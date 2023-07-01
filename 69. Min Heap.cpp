#include <bits/stdc++.h> 
class heap{
    int arr[100005];
    int size;
    public:
    heap(){
        arr[0] = -1;
        size=0;
    }
    void insert(int val){
        size++;
        arr[size] = val;
        int index = size;
        while(index>1){
            int parent = index/2;
            if(arr[index]<arr[parent]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else    break;
        }
    }
    int pop(){
        int val = arr[1];
        arr[1] = arr[size];
        size--;
        int index = 1;
        while(index<=size){
            int l = 2*index;
            int r = 2*index+1;
            int smallest=index;
            if(l<=size and arr[l]<arr[index]) {
                smallest = l;
            }
            if(r<=size and arr[r]<arr[smallest]){
                smallest = r;
            }
            if(smallest!=index){
                swap(arr[smallest],arr[index]);
                index = smallest;
            }
            else    break;
        }
        return val;
    }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    heap h;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(q[i][0]==0){
            h.insert(q[i][1]);
        }
        else {
            ans.push_back(h.pop());
        }
    }
    return ans;
}
