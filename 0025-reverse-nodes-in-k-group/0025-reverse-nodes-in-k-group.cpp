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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Check group of length k

        ListNode *temp = head;
        int count =0;
        while(temp != NULL && count<k){
            temp = temp->next;
            count++;
        }

        if(count == k){
            ListNode *previous = NULL;
            ListNode *current = head;

            ListNode *nextNode;
            int i=0;
            while(i<k){
                nextNode = current->next;
                current->next = previous;
                previous = current;
                current = nextNode;
                i++;
            }
            ListNode *recursionAns = reverseKGroup(current,k);
            head->next = recursionAns;
            return previous;
        }
        else{
            return head;
        }

    }
};