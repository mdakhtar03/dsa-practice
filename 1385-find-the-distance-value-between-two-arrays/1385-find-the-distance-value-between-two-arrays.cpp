class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(begin(arr1), end(arr1));
        sort(begin(arr2), end(arr2));
        int count=0; bool flag = true;
        for(int i=0; i<arr1.size(); i++){
            for(int j=0; j<arr2.size() ; j++){
                if(abs(arr1[i] - arr2[j]) <=d){
                    flag = false;
                    break;
                }
            }
            if(flag){
                count++;
            }
            flag = true;
        }
        return count;
    }
};