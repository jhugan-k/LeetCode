class Solution {
public:
    int solve(int left, int right, vector<int> &arr, vector<vector<int>> &dp){
        //left and right shift dynamically
        // base case: if no baloon between l&r : return 0
        if((left + 1) == right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int ans = 0;

        for(int i = left + 1; i < right; i++){
            int coin = arr[left] * arr[right] * arr[i];
            int leftCoin = solve(left, i, arr, dp);
            int rightCoin = solve(i, right, arr, dp);
            ans = max(ans, (coin + rightCoin + leftCoin));
        }

        return dp[left][right] = ans; // max of all possible 'last' points

    }
    int maxCoins(vector<int>& nums) {
        // check each balloon as the last baloon to burst between fixed range
        // if its the last baloon, then no more lie in between, and coins gained are n[left]*n[right] * nums[i]
        // recursively solve left and right part between i-left nad i-right
        // pad main array with 1s

        vector<int> arr;
        arr.push_back(1);
        for(auto it : nums) arr.push_back(it);
        arr.push_back(1);

        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1, -1));

        return solve(0, arr.size()-1, arr,dp);
    }
};