/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        unordered_map<Node*, bool> visited;

        Node *temp = head;
        while(temp != NULL){
            if(visited[temp] == false){
                visited[temp] = true;
            }
            else{
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};