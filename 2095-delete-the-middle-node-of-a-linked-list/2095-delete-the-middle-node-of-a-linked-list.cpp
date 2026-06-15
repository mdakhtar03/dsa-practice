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
    ListNode* deleteMiddle(ListNode* head) {
        //Use Fast and Slow 
        if(head->next == NULL){
            return NULL;
        }

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev = head;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast->next){
                fast = fast->next;
            }
        }
        //slow pointing to the mid node
        while(prev->next != NULL && prev->next != slow){
            prev=prev->next;
        }
        //Now deletion
        prev->next = slow->next;

        slow->next = NULL;

        delete slow;
        return head;
        

    }
};