#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node *reverseLinkedList(Node *head){
	Node *prev,*curr,*nex;
	prev=NULL;
	curr = head;
	while(curr){
		nex = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;
	}
	head = prev;
	return head;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head==NULL)	return head;
	Node *dummy = new Node(0);
	dummy->next = head;
	Node *curr,*pre,*nex;
	curr = pre = nex = dummy;
	int cnt = 0;
	while(curr->next!=NULL)	{
		curr = curr->next;
		cnt++;
	}
	int i = 0,k;
	while(true){
		if(i==n)	break;
		k = b[i++];
		if(pre==NULL or pre->next==NULL)		break;
		if(k==0)	continue;
        if (k == 1) {
                pre = pre->next;
                continue;
        }
        if(k>cnt)	k = cnt;
		curr = pre->next;
		nex = curr->next;
		
		for(int i=1;i<k;i++){
			curr->next = nex->next;
			nex->next = pre->next;
			pre->next = nex;
			nex = curr->next;
		}
		cnt-=k;
		pre = curr;
	}
	// if(k>cnt){
	// 	pre->next = reverseLinkedList(pre->next);
	// }
	return dummy->next;
}