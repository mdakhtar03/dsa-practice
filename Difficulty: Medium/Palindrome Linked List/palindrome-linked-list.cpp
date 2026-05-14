/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        Node *slow = head;
        Node *fast = head;
        while(fast->next !=NULL){
            
            fast = fast->next;
            if(fast->next != NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        
        //reverse
        Node *prev = NULL;
        Node *temp = slow;
        Node *nextNode;
        
        while(temp != NULL){
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp=nextNode;
        }
        Node *i = prev;
        Node *j = head;
        while(j != NULL && i != NULL){
            if(i->data != j->data){
                return false;
            }
            i=i->next;
            j=j->next;
        }
        
        return true;
        
    }
};