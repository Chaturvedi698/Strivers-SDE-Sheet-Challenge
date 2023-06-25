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

Node *firstNode(Node *head)
{
    //    Write your code here.
    if(head==NULL or head->next == NULL) return  NULL;
    // if(head->next==NULL) return head;
    bool flag = false;
    Node* fast = head, *slow = head;
    while(fast!=NULL and slow !=NULL){
        fast = fast->next;
        if(fast!=NULL) fast = fast->next;
        slow = slow->next;

        if(slow==fast){
        flag = true;
        break;
        }
    }
    if(!flag) return NULL;
    fast = head;
    while(fast!=slow){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}