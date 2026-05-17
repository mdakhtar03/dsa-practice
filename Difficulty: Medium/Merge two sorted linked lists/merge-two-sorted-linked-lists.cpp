/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedLL(Node *&list,Node* &head, Node *&tail){
        if(head == NULL && tail == NULL){
            head = list;
            tail = list;
        }
        else{
            tail->next = list;
            tail = list;
        }
        return head;
    }
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        auto it1 = head1;
        auto it2 = head2;
        
        Node *head=NULL;
        Node* tail=NULL;
        while(it1 && it2){
            if(it1->data <it2->data){
                Node* list = new Node(it1->data);
                sortedLL(list,head,tail);
                it1=it1->next;
            }
            else{
                Node *list = new Node(it2->data);
                sortedLL(list,head,tail);
                it2= it2->next;
            }
        }
         while(it1){

            Node* list = new Node(it1->data);

            sortedLL(list, head, tail);

            it1 = it1->next;
        }
        while(it2){
            Node *list = new Node(it2->data);
            sortedLL(list,head,tail);
            it2 = it2->next;
        }
        return head;
    }
};