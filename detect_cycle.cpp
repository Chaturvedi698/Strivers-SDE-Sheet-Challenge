/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

bool detectCycle(Node *head)
{
	//	Write your code here
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL and fast->next !=NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast->next!=NULL) fast = fast->next;
        else return false;

        if(fast==slow) return true;
    }
    return false;
}