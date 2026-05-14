

int isCircular(Node* head) {
    Node *temp = head;
    if(temp->prev != NULL){
        return 1;
    }
    return 0;
}
