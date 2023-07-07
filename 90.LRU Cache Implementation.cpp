#include<bits/stdc++.h>
class LRUCache
{
    class Node{
    
   
    public:
    int key;
    int value;
     Node *next,*prev;
    Node(int k,int v){
        key = k;
        value = v;
    }
    };
    Node *head,*tail;
    int cap;
    unordered_map<int,Node *> mp;
public:
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *newNode){
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node *delnode){
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        // Write your code here
        if(mp.find(key)!=mp.end()){
            Node *resNode = mp[key];
            int val = resNode->value;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key)!=mp.end()){
            Node *existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};
