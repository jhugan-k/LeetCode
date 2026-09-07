class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        long long total = prefix[n];
        long long ans = 0;

        for (int i = 1; i < n - 1; i++) {

            // left <= mid
            // prefix[i] <= prefix[j] - prefix[i]
            // prefix[j] >= 2 * prefix[i]
            long long low = 2 * prefix[i];

            // mid <= right
            // prefix[j] - prefix[i] <= total - prefix[j]
            // prefix[j] <= (total + prefix[i]) / 2
            long long high = (total + prefix[i]) / 2;

            // First j satisfying prefix[j] >= low
            auto first = lower_bound(
                prefix.begin() + i + 1,
                prefix.begin() + n,
                low
            );

            // First j satisfying prefix[j] > high
            auto last = upper_bound(
                prefix.begin() + i + 1,
                prefix.begin() + n,
                high
            );

            // [first, last) contains all valid j
            if (first < last) {
                ans += last - first;
                ans %= MOD;
            }
        }

        return ans;
    }
};