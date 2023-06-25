Node* findIntersection(Node *headA, Node *headB)
{
    //Write your code here
    if(headA==NULL || headB==NULL)  return NULL;
    Node * a,*b;
    a = headA;
    b = headB;
    while(a!=b){
        a = a==NULL?headB:a->next;
        b = b==NULL?headA:b->next;
    }
    return a;
}