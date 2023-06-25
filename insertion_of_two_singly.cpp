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

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;
    bool flag1 = true, flag2 = true;
    while (true)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == NULL and flag1)
        {
            temp1 = secondHead;
            flag1 = false;
        }
        else if (temp1 == NULL and !flag1)
        {
            return NULL;
        }

        if (temp2 == NULL and flag2)
        {
            temp2 = firstHead;
            flag2 = false;
        }
        else if (temp2 == NULL and !flag2)
        {
            return NULL;
        }

        if (temp1 == temp2)
            return temp2;
    }
}
