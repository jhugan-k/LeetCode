class Solution {
public:
    // need i and previous index
    int solve(int i, int prevIndex, vector<int> &nums, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;
        if(dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];
        int take = 0;
        if(prevIndex == -1 || nums[i] > nums[prevIndex]){
            // can take
            take = 1 + solve(i+1, i, nums, dp);
        }
        int notTake = solve(i+1, prevIndex, nums, dp);
        return dp[i][prevIndex + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        // DP: [index][prevIndex]
        // +1 offset (to hold -1)
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return solve(0, -1, nums,dp);
    }
};