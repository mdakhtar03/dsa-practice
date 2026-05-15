/* Node is defined as
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
    
    void insert(Node *&ListType, Node *&head, Node *&tail){
        
        if(head == NULL && tail == NULL){
            head = ListType;
            tail = ListType;
        }
        else{
           tail->next = ListType;
           tail = ListType;
        }
        
    }
    Node* segregate(Node* head) {
        Node *zeroHead = NULL;
        Node *zeroTail = NULL;
       
        Node *oneHead = NULL;
        Node *oneTail = NULL;
       
        Node *twoHead = NULL;
        Node *twoTail = NULL;
       
       Node *temp = head;
       while(temp != NULL){
           Node* ListType = temp;
           temp = temp->next;
           ListType->next = NULL;
           
           if(ListType->data == 0){
               insert(ListType, zeroHead, zeroTail);
           }
           else if(ListType -> data == 1){
               insert(ListType, oneHead ,oneTail);
           }
           else if(ListType -> data == 2){
                insert(ListType, twoHead ,twoTail);
           }
          
       }
       
       if(zeroHead != NULL){
           if(oneHead != NULL){
               zeroTail->next = oneHead;
               oneTail->next = twoHead;
               return zeroHead;
           }
           else{
               //No 1's
               zeroTail -> next = twoHead;
               return zeroHead;
           }
       }
       else{
           if(oneHead != NULL){
               oneTail->next = twoHead;
               return oneHead;
           }
           else{
               return twoHead;
           }
           
       }
        
    }
    
    
    
   
    
    
};