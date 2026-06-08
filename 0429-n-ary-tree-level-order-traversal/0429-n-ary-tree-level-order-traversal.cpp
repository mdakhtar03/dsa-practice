/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root,vector<vector<int>> &levelOrderAns
    ,vector<int> &ans, queue<Node*> q ){

        if(!root){
            return levelOrderAns;
        }

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                levelOrderAns.push_back(ans);
                ans.clear();
            }
            if(temp != NULL)
            ans.push_back(temp->val);
            if(temp != NULL)
            for(auto child:temp->children){
                q.push(child);
            }
            
        }

    return levelOrderAns;


    }



    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levelOrderAns;
        vector<int> ans;
        queue<Node*> q;
        
        return levelOrder(root, levelOrderAns, ans,q);



    }
};