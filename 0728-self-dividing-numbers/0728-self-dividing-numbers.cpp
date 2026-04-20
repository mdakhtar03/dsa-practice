class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int remainder, copy;
        bool flag = false;
        vector<int> ans;
        while (left <= right) {
            copy = left;
            flag=false;
            while (copy) {
                remainder = copy % 10;
                if ((remainder == 0) || (left % remainder != 0)) {
                    flag = true;
                    break;
                }
                copy = copy / 10;
            }
            if (!flag) {
                ans.push_back(left);
            }
            left++;
        }
        return ans;
    }
};