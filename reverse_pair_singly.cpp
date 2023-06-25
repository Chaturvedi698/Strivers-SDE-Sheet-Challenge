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
 Node* reverse(Node* head,int n, int b[], int index){
	 while(b[index]==0) index++;
	 
	 if(!head or !head->next or index>=n) return head;
	 int target = b[index];
	 Node* prev = NULL, *curr = head,*next = head;
	 while(curr!=NULL and target--!=0){
		 next = curr->next;
		 curr->next = prev;
		 prev = curr;
		 curr = next;
	 }
	 head->next = reverse(curr,n,b,index+1);
	 return prev;
 }
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(!head) return NULL;

	return reverse(head,n,b,0);
}