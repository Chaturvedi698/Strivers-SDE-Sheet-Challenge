/*
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
*/

Node *findMiddle(Node *head)
{
    // Write your code here]
    int size = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        curr = curr->next;
        size++;
    }
    Node *temp = head;
    //  if(size%2==0){
    for (int i = 0; i < size / 2; i++)
    {
        temp = temp->next;
        // }
    }
    return temp;
}
