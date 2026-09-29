class Solution {
public:
    // each half has sum = totalSum / 2.
    // try to pick numbers which have sum - totalSum / 2
    // take / not take
    // recursion -> DP 

    bool solve(vector<int> &nums, int i, int target){ //is it possible to make sum target using indexes upto i?
        //base case: i == 0: works if nums[0] == target
        //base case: target = 0: can always make sum 0: not taking.

         
        if(target == 0) return true;
        if(i == 0) return (nums[0] == target); // ** target == 0 before this: sum 0 always possible

        bool take = false;
        if(nums[i] <= target) take = solve(nums, i-1, target - nums[i]); //take if allowed and move backwards to search remaining
        bool notTake = solve(nums, i-1, target); //dont take and move backwards
        return (take || notTake); //if any path returns true 
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for(auto it : nums) sum += it;
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        // implement dp. changing state: target, index. 2D dp 
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1));
        //base case: index 0 and target 0
        for(int j = 0; j <= target; j++){
            dp[0][j] = (nums[0] == j); //i == 0
        }
        for(int i = 0; i < nums.size(); i++){
            dp[i][0] = true; //target == 0
        }
        //build remaining 
        for(int i = 1; i < nums.size(); i++){
            for(int j = 1; j <= target; j++){
                bool take = false;
                if(nums[i] <= j) take = dp[i-1][j - nums[i]]; //take if allowed and move backwards to search remaining
                bool notTake = dp[i-1][j]; //dont take and move backwards
                dp[i][j] = (take || notTake); //if any path returns true
            }
        }
        return dp[nums.size()-1][target];
    }
};