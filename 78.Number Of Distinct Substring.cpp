#include <bits/stdc++.h>
class Node{
    Node *links[26];
    public:
    Node(){
        for(int i=0;i<26;i++){links[i]=NULL;}
    }
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *newNode){
        links[ch-'a'] = newNode;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
};
int distinctSubstring(string &word) {
    //  Write your code here.
    Node *root = new Node();
    int cnt=0;
    for(int i=0;i<word.length();i++){
        Node *node = root;
        for(int j=i;j<word.length();j++){
            if(node->containsKey(word[j])==false){
                cnt++;
                node->put(word[j],new Node());
            }
            node = node->get(word[j]);
        }
    }
    return cnt;

}
