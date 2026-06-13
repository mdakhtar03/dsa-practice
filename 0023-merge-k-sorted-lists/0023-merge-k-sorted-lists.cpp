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
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Step 1 initalize minHeap
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        //Step2: add all first lists
        int totalRows = lists.size();

        for(int i=0; i<totalRows; i++){
            ListNode* firstList = lists[i];
            if(firstList != NULL){
                pq.push(firstList);
            }
        }
        //Step 3: Make list
        while(!pq.empty()){
            
            ListNode* minElement = pq.top();
            pq.pop();

            //First Node
            if(head == NULL && tail == NULL){
                head = minElement;
                tail = minElement;
            }
            else{
                //Head contain come node
                tail->next = minElement;
                tail = minElement;
            }

            if(minElement->next != NULL){
                pq.push(minElement->next);
            }

        }
        return head;
    }
};