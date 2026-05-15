// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
  
  
void insert(struct Node* &nodeType,struct Node*& head,struct Node*& tail){
    if(head == NULL && tail == NULL){
        head = nodeType;
        tail = nodeType;
    }
    else{
        tail->next = nodeType;
        tail = nodeType;
    }
}
  

  
  
  
    struct Node* partition(struct Node* head, int x) {
        struct Node* nodeLessThanXHead = NULL;
        struct Node* nodeLessThanXTail = NULL;
        struct Node* nodeEqualXHead = NULL;
        struct Node* nodeEqualXTail = NULL;
        struct Node* nodeGreaterThanXHead = NULL;
        struct Node* nodeGreaterThanXTail = NULL;
        
        
        
        struct Node* temp = head;
        
        while(temp != NULL){
            struct Node *nodeType = temp;
            temp = temp->next;
            nodeType->next = NULL;
            
            if(nodeType->data<x){
                insert(nodeType,nodeLessThanXHead,nodeLessThanXTail); 
            }
            else if(nodeType->data == x){
                insert(nodeType,nodeEqualXHead,nodeEqualXTail);
            }
            else {
                insert(nodeType,nodeGreaterThanXHead,nodeGreaterThanXTail);
            }
            
        }
        
        if(nodeLessThanXHead == NULL){
            if(nodeEqualXHead == NULL){
                return nodeGreaterThanXHead;
            }
            else{
                nodeEqualXTail->next =  nodeGreaterThanXHead;
                return nodeEqualXHead;
            }
        }
        else{
            if(nodeEqualXHead == NULL){
                nodeLessThanXTail->next = nodeGreaterThanXHead;
                return nodeLessThanXHead;;
            }
            else{
                nodeLessThanXTail->next = nodeEqualXHead;
                nodeEqualXTail->next = nodeGreaterThanXHead;
                return nodeLessThanXHead;
            }
        }
        
        
        
        
    }
};