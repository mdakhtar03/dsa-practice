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
    void reverseLL(ListNode *&head){
        ListNode* prev = NULL;
        ListNode* current = head;
        
        while(current != NULL){
            ListNode *nextNode = current->next;
            current->next = prev;
            prev=current;
            current = nextNode;
        }
        head = prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = l1;
        ListNode* prev = NULL;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL || carry !=0 ){
            int L1=0 , L2=0;
            if(l1 != NULL){
                L1 = l1->val;
                
            }
            if(l2 != NULL){
                L2 = l2->val;
                
            }
            int sum = L1+ L2 +carry;
            int remainder = sum%10;
            carry = sum/10;
            if(l1 != NULL){
                l1->val = remainder;
                prev = l1;
                l1 = l1->next;
            }
            else {
                ListNode *newNode = new ListNode(remainder);
                prev->next = newNode;
                prev = newNode;
            }
            
            if(l2 != NULL){
                l2 = l2->next;
            }
        
        }
       
        return head;
    }
};