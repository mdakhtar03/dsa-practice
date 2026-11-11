class Solution {
using  ll = long long;
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll price_0 = 1LL * cost1*need1+ 1LL * cost2*need2;
        ll price_1 = 1LL * costBoth * min(need1,need2) + (need1 > need2
                      ? 1LL * cost1 * (need1 - need2)
                      : 1LL * cost2 * (need2 - need1));
        ll price_2 = 1LL * costBoth*max(need1,need2);
        return min(min(price_0,price_1),price_2);
    }
};