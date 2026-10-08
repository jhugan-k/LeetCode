class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size(); 
        long long s = 0;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0) s += nums[i];
            else s -= nums[i];
            
        }
        long long pref = 0;
        const long long neg = -(1LL << 60);

        long long maxPref[2] = {neg, neg};
        maxPref[0] = 0;

        long long minEven = (1LL << 60);

        for(int i = 1; i <= n; i++){
            if((i-1) % 2 == 0) pref += nums[i-1];
            else pref -= nums[i-1];

            int parity = i%2;

            minEven = min(minEven, pref - maxPref[parity]);
            maxPref[parity] = max(maxPref[parity], pref);
        }
        return max(s, s - 2 *minEven);
    }
};