class Solution {
public:
    using ll = long long;
    int mod = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> numbers;
        vector<ll> prefixSum;
        vector<ll> digits(n);
        vector<ll> powerOften(n + 1);

        powerOften[0] = 1;
        for (int i = 1; i <= n; i++)
            powerOften[i] = (powerOften[i - 1] * 10LL) % mod;

        int cnt = 0;
        for (char ch : s) {
            if (ch != '0')
                cnt++;
            numbers.push_back(cnt);
        }

        digits[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int d = s[i] - '0';
            if (d != 0)
                digits[i] = (digits[i - 1] * 10 + d) % mod;
            else
                digits[i] = digits[i - 1];
        }

        prefixSum.push_back(s[0] - '0');
        for (int i = 1; i < n; i++)
            prefixSum.push_back(prefixSum.back() + (s[i] - '0'));

        vector<int> result(queries.size());

        for (int i = 0; i < queries.size(); i++) {

            int l = queries[i][0];
            int r = queries[i][1];

            ll sum = prefixSum[r] - (l == 0 ? 0 : prefixSum[l - 1]);

            ll k = numbers[r] - (l == 0 ? 0 : numbers[l - 1]);

            ll x;
            if (l == 0)
                x = digits[r];
            else
                x = (digits[r] - (digits[l - 1] * powerOften[k]) % mod + mod) % mod;

            result[i] = (sum % mod) * (x % mod) % mod;
        }

        return result;
    }
};