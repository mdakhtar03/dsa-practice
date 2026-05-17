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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       
        //Total no of nodes
        int Nodes = 0;
        ListNode* temp= head;
        while(temp != NULL){
            Nodes++;
            temp = temp->next;
        }
        //Size of Each part
        int idealPartSize = Nodes/k;
        int remainingNodes = Nodes%k;
        vector<ListNode*> ans(k, NULL);
        temp = head;
        for(int i=0; i<k && temp;i++){
            

            ans[i] = temp;
            int realSize = idealPartSize + (remainingNodes-- > 0 ? 1 : 0); 
            for(int j=0;j<realSize-1 ; j++){
                temp = temp->next; 
            }
            ListNode *nextNode = temp->next;
            temp->next = NULL;
            temp = nextNode;
        }
        return ans;

    }
};