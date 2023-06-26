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
	Node* merge(Node* head1, Node* head2){
		Node* temp = new Node(0);
		Node* curr = temp;
		
			while(head1!=NULL and head2!=NULL){
			 if(head1->data<head2->data){
				 temp->child = head1;
				 temp = temp->child;
				 head1 = head1->child;
			 }
			 else{
				 temp->child = head2;
				 temp = temp->child;
				 head2 = head2->child;
			 }
		}
		if(head1!=NULL) temp->child = head1;
		else temp->child = head2;
		return curr->child;
	}
Node* flattenLinkedList(Node* head) 
{

		// Write your code here
		if(head==NULL or head->next==NULL) return head;
		Node* root =flattenLinkedList(head->next);
	;
		head->next = NULL;
		head = merge(head,root);
		return head;
}
