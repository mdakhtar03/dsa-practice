/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
          if(head == NULL){
            return head;
        }
        ListNode *previous = head;
        ListNode *current = head->next;
        ListNode *nextNode;
        
        while(current != NULL){
            if(previous->val == current->val){
             
                nextNode = current->next;
                current->next = NULL;
                delete current;
                previous->next = nextNode;
                current = nextNode;
            }
            else{
                previous=current;
                current = current->next;
            }
                
        }
        return head;
    }
};