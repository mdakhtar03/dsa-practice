class Solution {
public:
    int n;
    int arr[2][101][101];
    int solve(vector<int> &piles, int person,int i, int M){
        if(i>=piles.size()){
            return 0;
        }
        int stones = 0;
        int result = person==1 ? -1:INT_MAX;
        for(int X=1 ; X <= min(2*M, n-i) ; X++){
            stones += piles[i+X-1];
            if(person){
                result =  max(result, stones + solve(piles,0,i+X, max(M,X)));
            }
            else{
                result = min(result,solve(piles,1,i+X, max(M,X)));
            }
        }
        return result;

    }
    int solveUsingMem(vector<int> &piles, int person,int i, int M){
        if(i>=piles.size()){
            return 0;
        }
        if(arr[person][i][M] != -1){
            return arr[person][i][M];
        }
        int stones = 0;
        int result = person==1 ? -1:INT_MAX;
        for(int X=1 ; X <= min(2*M, n-i) ; X++){
            stones += piles[i+X-1];
            if(person){
                result =  max(result, stones + solveUsingMem(piles,0,i+X, max(M,X)));
            }
            else{
                result = min(result,solveUsingMem(piles,1,i+X, max(M,X)));
            }
        }
        arr[person][i][M] = result;
        return result;

    }

    int stoneGameII(vector<int>& piles) {
        
        memset(arr,-1,sizeof(arr));
        int person = 1; 
        int i=0, M=1;
        n = piles.size();
        int j=piles.size();
        int ans = solveUsingMem(piles,person, i,M);

        return ans;
    }
};