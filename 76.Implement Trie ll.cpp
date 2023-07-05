#include <bits/stdc++.h> 
class Node{
    Node *child[26];
    int cntPrefix;
    int cntEndsWith;
    public:
    Node(){
        for(int i=0;i<26;i++)   child[i] = NULL;
        cntPrefix = 0;
        cntEndsWith = 0;
    }
    bool containsKey(char ch){
        return child[ch-'a']!=NULL;
    }
    void put(char ch,Node *newNode){
        child[ch-'a'] = newNode;
    }
    Node *get(char ch){
        return child[ch-'a'];
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void decreasePrefix(){
        cntPrefix--;
    }
    void increaseEnd(){
        cntEndsWith++;
    }
    void decreaseEnd(){
        cntEndsWith--;
    }
    int getPrefix(){
        return cntPrefix;
    }
    int getEndsWith(){
        return cntEndsWith;
    }
};
class Trie{
    Node *root;
    public:

    Trie(){
        // Write your code here.
        root= new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *temp = root;

        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
            temp->increasePrefix();
        }
        temp->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *temp = root;

        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                return 0;
            }
            temp = temp->get(word[i]);
        }
        return temp->getEndsWith();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *temp = root;

        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                return 0;
            }
            temp = temp->get(word[i]);
        }
        return temp->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node *temp = root;

        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])==false){
                return;
            }
            temp = temp->get(word[i]);
            temp->decreasePrefix();
        }
        temp->decreaseEnd();
    }
};
