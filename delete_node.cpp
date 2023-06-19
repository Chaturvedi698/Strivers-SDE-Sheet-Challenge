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

// by reverse approach

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    Node *curr = head, *next = head, *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (K == 1)
    { // for the 1st node
        Node *curr1 = prev;
        prev = prev->next;
        curr1->next = NULL;
        Node *curr = prev, *next = prev, *prev1 = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev1;
            prev1 = curr;
            curr = next;
        }
        return prev1;
    }
    Node *temp = NULL;
    Node *temp1 = prev;
    int i = 1;
    while (i != K)
    {
        i++;
        temp = temp1;
        temp1 = temp1->next;
    }
    temp->next = temp1->next;

    Node *curr1 = prev, *next1 = prev, *prev1 = NULL;
    while (curr1 != NULL)
    {
        next1 = curr1->next;
        curr1->next = prev1;
        prev1 = curr1;
        curr1 = next1;
    }
    return prev1;
}


// by fast and slow pointer appraoch

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

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    Node *curr = new Node();
    curr->next = head;
    Node *fast = curr, *slow = curr;
    while (K--)
    {
        fast = fast->next;
    }

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return curr->next;
}
