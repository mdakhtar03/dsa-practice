
class Info{
  public:
    int element;
    int rowIndex;
    int colIndex;
    
    Info(int val, int row, int col){
        element = val;
        rowIndex = row;
        colIndex = col;
    }
};

class compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->element > b->element;
    }
};

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
       vector<int> ans;
       priority_queue<Info*, vector<Info*>, compare> pq;
       
       
       int totalCol = mat[0].size();
       int totalRow = mat.size();
       for(int i=0; i<totalRow; i++){
           int element = mat[i][0];
           Info* temp = new Info(element,i,0);
           pq.push(temp);
       }
       
       while(!pq.empty()){
           Info* front = pq.top();
           pq.pop();
           
           int element = front->element;
           int rIndex = front->rowIndex;
           int cIndex = front->colIndex;
           
           ans.push_back(element);
           
           if(cIndex+1 < totalCol){
              int element = mat[rIndex][cIndex+1];
              int newRowIndex = rIndex;
              int newColIndex = cIndex+1;
              Info* temp = new Info(element,newRowIndex,newColIndex);
              pq.push(temp);
           }
           
       }
       return ans;
       
    }
    
    
    
    
    
    
    
    
    
    
};