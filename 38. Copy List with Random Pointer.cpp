#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    map<LinkedListNode<int> *,LinkedListNode<int> *> mp;

    LinkedListNode<int> *iter = head;
    LinkedListNode<int> *pseudohead;
    while(iter!=NULL){
        LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
        mp[iter] = copy;
        iter = iter->next;
    }

    iter = head;
    pseudohead = mp[iter];
    while(iter!=NULL){
        LinkedListNode<int> *copy = mp[iter];

        if(iter->next) copy->next = mp[iter->next];
        if(iter->random!=NULL) copy->random = mp[iter->random];
        else copy->random = NULL;

        iter = iter->next;
    }
    return pseudohead;
}
