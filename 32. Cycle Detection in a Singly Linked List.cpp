bool detectCycle(Node *head)
{
	//	Write your code here
    Node *slow,*fast;
    slow = fast = head;

    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow)  return true;
        
    }
    return false;
}