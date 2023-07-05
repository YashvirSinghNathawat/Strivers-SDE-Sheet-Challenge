#include <bits/stdc++.h> 
struct Node{
    Node *links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node *newNode){
        links[bit] = newNode;
    }
    Node *get(int bit){
        return links[bit];
    }
};
class Trie{
    
    public:
    Node *root;
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containsKey(bit)==false){
                node->put(bit,new Node());
            }
            node = node->get(bit);   
        }
    }
    int getMax(int num){
        Node *node = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else    node = node->get(bit);
        }
        return maxNum;
    }
};
int maximumXor(vector<int> A)
{
    // Write your code here.
    int ans = 0;
    int n = A.size();
    Trie t;
    for(int i=0;i<n;i++)        t.insert(A[i]);
    for(int x=0;x<n;x++){
        ans = max(ans,t.getMax(A[x]));
    }
    return ans;

      
}