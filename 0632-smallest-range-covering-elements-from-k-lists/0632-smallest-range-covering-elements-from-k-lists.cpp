class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int val, int rIndex, int cIndex){
        data = val;
        rowIndex = rIndex;
        colIndex = cIndex;
    }
};

class compare{
    public:
    bool operator()(Info* a , Info* b){

    return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        //Step1 push all first Index values
        for(int i=0; i<nums.size(); i++){
            int element = nums[i][0];
            Info* temp = new Info(element, i,0);
            pq.push(temp);
            
            //Update max and mini
            maxi = max(element, maxi);
            mini = min(element,mini);

        }

        //Step2 now you have maxi and mini now you have to minimize its range
        int minAns = mini;
        int maxAns = maxi;

        while(!pq.empty()){
            Info* front = pq.top();
            pq.pop();

            int element = front->data;
            int rIndex = front->rowIndex;
            int cIndex = front->colIndex;
        // Update the mini
            mini = element;
            if(maxi-mini < maxAns - minAns){
                maxAns = maxi;
                minAns = mini;
            }

            if(cIndex+1 < nums[rIndex].size()){
                int element = nums[rIndex][cIndex+1];
                Info* temp = new Info(element,rIndex,cIndex+1);
                pq.push(temp);
                maxi = max(element,maxi);
            }
            else{
                break;
            }

        }

        return {minAns,maxAns};

    }
};