class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int s = 0, e = arr.size() - 1;
        int ans;
        int mid;
        while (s <= e) {
            mid = (s+e)/2;
            if (mid - 1 >= 0 && arr[mid] < arr[mid - 1]) {
                e = mid - 1;
            } else {
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }
};