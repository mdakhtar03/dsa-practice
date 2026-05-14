/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        Node *temp = head;
        Node *prev = NULL;
        Node *nextNode;
        if(temp->next == NULL){
            return head;
        }
        
        while(temp  != NULL){
            nextNode = temp->next;
            temp->next = prev;
            prev=temp;
            temp=nextNode;
        
        }
        
        head = prev;
        return head;
    }
};