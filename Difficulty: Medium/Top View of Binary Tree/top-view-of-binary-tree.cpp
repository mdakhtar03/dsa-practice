/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
       queue<pair<Node*, int>> q;
       q.push(make_pair(root,0));
       unordered_map<int,Node*> mp;
       
       int minDist = INT_MAX;
       int maxDist = INT_MIN;
       
        while(!q.empty()){
            pair<Node*,int> frontPair = q.front();
            q.pop();
            Node* temp = frontPair.first;
            int distant = frontPair.second;
            
            minDist = min(minDist, distant);
            maxDist = max(maxDist, distant);
            
            
            if(mp.find(distant) == mp.end()){
                mp[distant] = temp;
            }
            //left
            if(temp->left != NULL){
                q.push(make_pair(temp->left,distant-1));
            }
            if(temp->right != NULL){
                q.push(make_pair(temp->right,distant+1));
            }
            
        }
        vector<int> ans;
        
        for(int i=minDist; i<=maxDist; i++){
            ans.push_back(mp[i]->data);
        }
        
        
        return ans;
    }
    
    
    
};