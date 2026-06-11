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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void getLength(ListNode* head, int &len){
        ListNode* temp = head;
        while(temp){
            ++len;
            temp = temp->next;
        }
    }
    TreeNode* buildBST(ListNode* &head, int len){
        if(head == NULL){
            return NULL;
        }
        if(len == 0){
            return NULL;
        }
        //L
        TreeNode* leftSubTree = buildBST(head, len/2);
        // N
        int element = head->val;
        TreeNode* root = new TreeNode(element);
        root->left = leftSubTree;
        head = head->next;
        //R
        TreeNode* rightSubTree = buildBST(head, len-len/2-1);
        root->right = rightSubTree;
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        getLength(head, len);
        TreeNode* root = new TreeNode();
        root=buildBST(head, len);
        return root;
    }
};