#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *findMiddle(LinkedListNode<int> *head){
    LinkedListNode<int> *s,*f;
    s = f = head;
    while(f->next!=NULL and f->next->next!=NULL){
        s = s->next;
        f = f->next->next;
    }
    return s;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head){
    LinkedListNode<int> *prev,*curr,*nex;
    prev = NULL;
    curr = head;
    while(curr!=NULL){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head = prev;
    return head;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL or head->next==NULL)  return true;
    LinkedListNode<int> *middle = findMiddle(head);
    middle->next = reverseLinkedList(middle->next);

    LinkedListNode<int> *h1,*h2;
    h1 = head;
    h2 = middle->next;
    while(h2!=NULL){
        if(h1->data != h2->data)    return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;

}