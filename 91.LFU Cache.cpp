#include <bits/stdc++.h> 
class Node{
    public:
    int key,value,cnt;
    Node *prev,*next;
    Node(int k,int v){
        key = k;
        value = v;
        cnt = 1;
    }
};
class List{
    
    public:
    Node *head,*tail;
    int size;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *newNode){
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }
    void removeNode(Node *delNode){
        Node *delprev = delNode->prev;
        Node *delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
};
class LFUCache
{   
    map<int,Node *> keyNode;
    map<int,List *> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    void updateFreqListMap(Node *node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFreq and freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        List *nextHigherFreq = new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherFreq = freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreq->addFront(node);
        freqListMap[node->cnt] = nextHigherFreq;
        keyNode[node->key] = node;
    }
    int get(int key)
    {
        // Write your code here.
        if(keyNode.find(key)!=keyNode.end()){
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(maxSizeCache==0) return;
        if(keyNode.find(key)!=keyNode.end()){
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else{
            if(currSize==maxSizeCache){
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq= 1;
            List *listFreq = new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};
