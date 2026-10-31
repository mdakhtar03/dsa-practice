class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<long long> sum;
    vector<long long> sumSq;
    vector<int> lazy;

    void pushDown(int node, int start, int end) {
        if (lazy[node] == 0) return;

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;
        long long val = lazy[node];

        // Update left child
        long long lenL = mid - start + 1;
        sumSq[leftChild] = (sumSq[leftChild] + 2 * val * sum[leftChild] + val * val % MOD * lenL) % MOD;
        sum[leftChild] = (sum[leftChild] + val * lenL) % MOD;
        lazy[leftChild] += val;

        // Update right child
        long long lenR = end - mid;
        sumSq[rightChild] = (sumSq[rightChild] + 2 * val * sum[rightChild] + val * val % MOD * lenR) % MOD;
        sum[rightChild] = (sum[rightChild] + val * lenR) % MOD;
        lazy[rightChild] += val;

        lazy[node] = 0; // Clear current node's lazy flag
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (l <= start && end <= r) {
            long long len = end - start + 1;
            sumSq[node] = (sumSq[node] + 2LL * val * sum[node] + 1LL * val * val % MOD * len) % MOD;
            sum[node] = (sum[node] + 1LL * val * len) % MOD;
            lazy[node] += val;
            return;
        }

        pushDown(node, start, end);
        int mid = start + (end - start) / 2;

        if (l <= mid) {
            update(2 * node, start, mid, l, r, val);
        }
        if (r > mid) {
            update(2 * node + 1, mid + 1, end, l, r, val);
        }

        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sumSq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> lastPos;
        long long totalSum = 0;

        for (int j = 0; j < n; j++) {
            // If the element has not been seen before, its previous index defaults to -1
            int p = lastPos.count(nums[j]) ? lastPos[nums[j]] : -1;

            // Increment the distinct element count for all valid subarrays ending at j
            update(1, 0, n - 1, p + 1, j, 1);

            // Accumulate the current state's sum of squares (root node covers all active prefixes)
            totalSum = (totalSum + sumSq[1]) % MOD;

            // Update the last seen position of the element
            lastPos[nums[j]] = j;
        }

        return totalSum;
    }
};