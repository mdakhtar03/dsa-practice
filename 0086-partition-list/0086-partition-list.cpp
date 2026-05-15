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
    void insert(ListNode *&ListType , ListNode* &head, ListNode* &tail ){
        if(head == NULL && tail == NULL){
            head = ListType;
            tail = ListType;
        }
        else{
            tail->next = ListType;
            tail = ListType;
        }
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode *firstListHead = NULL;
        ListNode *firstListTail = NULL;
        ListNode *secondListHead = NULL;
        ListNode *secondListTail = NULL;
        
        ListNode *temp = head;
        while(temp != NULL){
            ListNode *ListType = temp;
            temp = temp->next;
            ListType->next = NULL;
            if(ListType->val<x){
                insert(ListType,firstListHead,firstListTail);
            }
            else{
                insert(ListType,secondListHead,secondListTail);
            }
        }
        if(firstListHead == NULL){
            return secondListHead;
        }
        else if(secondListHead == NULL){
            return firstListHead;
        }
        else {
            firstListTail->next = secondListHead;
        }
        return firstListHead;
    }
};