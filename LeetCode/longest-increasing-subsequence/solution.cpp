class Solution {
public:
    int solve(int i, int prevIndex, vector<int> &nums, vector<vector<int>> &dp){
        if(i >= nums.size()) return dp[i][prevIndex + 1] = 0;
        if(dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];

        int noTake = solve(i+1, prevIndex, nums, dp);
        int take = 0;
        if(prevIndex == -1 || nums[prevIndex] < nums[i]){
            //can take
            take = 1 + solve(i+1, i, nums, dp);
        }
        return dp[i][prevIndex + 1] = max(take, noTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        // take / notTake depending ov prevIndex
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,-1));
        // offset by 1 to accomodate -1

        return solve(0, -1, nums,dp);
    }
};