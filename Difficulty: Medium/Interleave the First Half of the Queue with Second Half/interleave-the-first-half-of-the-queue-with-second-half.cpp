class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> firstQueue;
        queue<int> secondQueue;
        
        int size  = q.size()/2;
        
        for(int i=0;i<size;i++){
            firstQueue.push(q.front());
            q.pop();
        }
         for(int i=0;i<size;i++){
            secondQueue.push(q.front());
            q.pop();
        }
        
       
        //Push
        while(!firstQueue.empty() &&!secondQueue.empty()){
            q.push(firstQueue.front());
            firstQueue.pop();
            q.push(secondQueue.front());
            secondQueue.pop();
        }
        
    }
};