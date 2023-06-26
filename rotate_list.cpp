/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(!head) return NULL;
     if(k==0) return head;
     Node* temp = head;
     // vector<int>data;
     int length= 0;
     while(temp){
          length++;
          temp = temp->next;
     }
     

     temp = head;
     int index = 0;
     int data[length];
     while(temp){
          data[(index+k)%length] = temp->data;
          index++;
          temp = temp->next;
     }
     temp= head;
     index = 0;
     while(temp){
          temp->data = data[index];
          index++;
          temp = temp->next;
     }
     return head;
}



/// second apporach without using extra space

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head==NULL or head->next==NULL or k==0) return head;
     int length = 1;
     Node* temp = head;
     while(temp->next){
          length++;
          temp = temp->next;
     }
     temp->next = head;
     k = k%length;
     k = length - k;
     while(k--){
          temp = temp->next;
     }
     head = temp->next;
     temp->next = NULL;
     return head;
}