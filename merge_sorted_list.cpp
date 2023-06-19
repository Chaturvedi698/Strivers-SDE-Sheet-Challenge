#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    Node<int> *head, *temp;
    if (first->data <= second->data)
    {
        head = first;
        first = first->next;
    }
    else
    {
        head = second;
        second = second->next;
    }
    head->next = NULL;
    Node<int> *curr = head;

    while (first != NULL and second != NULL)
    {
        if (first->data <= second->data)
        {
            temp = first;
            first = first->next;
        }
        else
        {
            temp = second;
            second = second->next;
        }
        curr->next = temp;
        curr = curr->next;
        curr->next = NULL;
    }
    if (first != NULL)
    {
        curr->next = first;
    }
    if (second != NULL)
    {
        curr->next = second;
    }

    return head;
}
