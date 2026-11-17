class Solution {
public:
    int n;
    string str;
    vector<vector<int>> costMemo;
    vector<vector<int>> memo;
    int findCost(int s, int e){

        if(costMemo[s][e] != -1){
            return costMemo[s][e];
        }
        int len = e-s+1;
        int minCost = INT_MAX;
        for(int d=1 ; d<len; d++){
            if(len % d != 0)
                continue;
            
            int cost = 0;
            for(int g = 0; g<d ; g++){
                int l = s + g;
                int r = l + (len/d-1)*d;

                while(l<r){
                    if(str[l] != str[r]){
                      cost++;  
                    }
                    l += d;
                    r -= d;
                }

            }

            minCost = min(minCost, cost);

        }

        return costMemo[s][e] = minCost;
    }
    int solveUsingRec(int s, int k){
        if(k == 0){
            if(s == n){
                return 0;
            }

            return INT_MAX;
        }

        if(memo[s][k] != -1){
            return memo[s][k];
        }

        if(s + 2*k > n){
            return INT_MAX;
        }

        int minCost = INT_MAX;
        for(int e=s+1; e<n; e++){
            int remainingCost = solveUsingRec(e+1, k-1);
            
            if(remainingCost == INT_MAX)
                continue;

            minCost = min(minCost,findCost(s,e)+remainingCost);
        }
        return memo[s][k] =  minCost;
    }
    int minimumChanges(string s, int k) {
        n = s.length();
        str = s;
        costMemo.assign(n+1, vector<int>(n+1, -1));
        memo.assign(n+1, vector<int> (k+1,-1));

        return solveUsingRec(0,k);
    }
};