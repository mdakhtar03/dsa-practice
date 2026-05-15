/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void reverse(Node* &head){
         Node *previous = NULL;
        Node *current = head;
        while(current != NULL){
            Node *nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        head = previous;
    }
    Node* addOne(Node* head) {
        //reverse a LL
        reverse(head);
        
        int carry =1;
        Node *temp = head;
        while(temp != NULL){
            int sum = temp->data + carry;
            int remainder = sum%10;
            temp->data =  remainder;
             carry = sum/10;
            
            if(temp ->next == NULL && carry !=0 ){
                Node *newNode = new Node(carry);
                temp->next = newNode;
                carry = 0;
            }
            
            temp = temp->next;
        }
        reverse(head);
        return head;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};