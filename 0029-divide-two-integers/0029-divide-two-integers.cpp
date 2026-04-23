class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long positiveDividend = abs((long long)dividend);
        long long positiveDivisor = abs((long long)divisor);
        long long ans;
        long long s = 0, e = positiveDividend;
        while (s <= e) {
            long long mid = s + ((e - s) >> 1);
            if (mid * positiveDivisor <= positiveDividend) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        if (dividend < 0 && divisor > 0) {
            return int(0 - ans);
        } else if ((dividend < 0 && divisor < 0) ||
                   (dividend > 0 && divisor > 0)) {
            return int(ans);
        }
        return int(0 - ans);
    }
};