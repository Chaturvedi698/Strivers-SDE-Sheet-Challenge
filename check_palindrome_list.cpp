#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
    LinkedListNode<int>* reverse(LinkedListNode<int>* head){
        if(head==NULL or head->next ==NULL) return head;
        LinkedListNode<int>* curr = head, *prev = NULL, *next = head;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL or head->next == NULL) return true;
    LinkedListNode<int>*slow = head,*fast = head , *middle;
    while(fast->next!=NULL and fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    middle = slow;

    middle->next = reverse(middle->next);

    LinkedListNode<int>* temp1 = head, *temp2 = middle->next;


    while(temp2!=NULL){
        if(temp1->data !=temp2->data){
            return false;
            break;
        }
        temp1= temp1->next;
        temp2 = temp2->next;
    }

    middle->next = reverse(middle->next);
    return true;
 
}