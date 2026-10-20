
class Solution {
public:
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int M = pattern.size();
        if (M == 0) return;

        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool KMPSearch(vector<int>& pattern, vector<int>& txt) {
        int N = txt.size();
        int M = pattern.size();

        if (M == 0) return true;
        if (M > N) return false;

        vector<int> lps(M, 0);
        computeLPS(pattern, lps);

        int i = 0, j = 0;

        while (i < N) {
            if (pattern[j] == txt[i]) {
                i++;
                j++;

                if (j == M) return true;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }

    bool isTrue(vector<int>& vec1, vector<int>& vec2) {
        vector<int> text = vec2;
        text.insert(text.end(), vec2.begin(), vec2.end());

        return KMPSearch(vec1, text);
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        // Check every proper divisor of n.
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                vector<int> vec1(
                    nums.begin() + start,
                    nums.begin() + start + k
                );

                vector<int> vec2(
                    sorted.begin() + start,
                    sorted.begin() + start + k
                );

                if (!isTrue(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
};
