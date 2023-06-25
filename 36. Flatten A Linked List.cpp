/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node *mergeTwoList(Node *a,Node *b){
	if(a->data > b->data)	swap(a,b);
	Node *res = a;
	while(a!=NULL and b!=NULL){
		Node *tmp = NULL;
		while(a!=NULL and a->data<=b->data){
			tmp = a;
			a = a->child;
		}
		tmp->child = b;
		swap(a,b);
	}
	return res;
}
Node *flatten(Node *root){
	if(root==NULL)	return NULL;
	if(root->next==NULL)	return root;
	root->next = flatten(root->next);
	root = mergeTwoList(root,root->next);
	return root;
}
Node* flattenLinkedList(Node* root) 
{
	// Write your code here
	root = flatten(root);
	root->next = NULL;
	Node * tmp = root;
	while(tmp!=NULL){
		tmp->next = NULL;
		tmp = tmp->child;
	}
	return root;
	
}
