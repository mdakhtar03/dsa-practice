class Solution {
public:
    int minimumCost(vector<int>& cost) {
        //maxHeap
        priority_queue<int> pq;
        for(int &c:cost){
            pq.push(c);
        }

        int minCost=0;
        int firstCandyCost=0;
        int secondCandyCost=0;
        while(!pq.empty()){

            firstCandyCost = pq.top();
            pq.pop();

            if(!pq.empty()){
                secondCandyCost = pq.top();
                pq.pop();
            }

            minCost += firstCandyCost + secondCandyCost;

            if(!pq.empty()){
                pq.pop();
            } 
            firstCandyCost=0;
            secondCandyCost=0;
            
        }

        return minCost;

    }
};