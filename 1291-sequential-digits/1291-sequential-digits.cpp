class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        vector<int> ans;
        for(int i=1;i<9;i++){
            q.push(i);
        }

       while(!q.empty()){
            int frontItem = q.front();
            q.pop();

            if(frontItem > high) continue;

            if(frontItem >= low && frontItem <= high){
                ans.push_back(frontItem);
            }

            int lastDigit = frontItem % 10;
            if(lastDigit != 9){
                int nextNum = frontItem * 10 + (lastDigit + 1);
                q.push(nextNum);
            }
        }

        return ans;
    }
};