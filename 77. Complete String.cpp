#include <bits/stdc++.h> 
class Node{
    Node *links[26];
    bool flag;
    public:
    Node(){
        for(int i=0;i<26;i++)   links[i] = NULL;
        flag = false;
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

    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag = true;
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;

        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])==false){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node *temp = root;

        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false)       return false;
            else{
                temp = temp->get(word[i]);
                if(temp->isEnd()==false)    return false;
            }
            
        }

        return temp->isEnd();
    }

};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie t;
    for(auto str:a){
        t.insert(str);
    }
    string ans="";
    for(auto str:a){
       if(t.search(str)){
           if(str.length()>ans.length())        ans = str;
           else if(str.length()==ans.length() and str<ans)    ans = str;
       } 
    }
    return ans==""?"None":ans;
}