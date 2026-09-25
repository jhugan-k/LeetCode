class Solution {
public:
    // split into two groups: + and - 
    // each smash is a transaction between groups. so order dosent matter
    // for minimum net weight: both groups should have ideally same sum : total / 2
    // for best split: find a subset with sum closest to total / 2.
    // basically find largest sum subset in range 0 to total/2


    int solve(vector<int> &stones, int i, int target, vector<vector<int>> &dp){
        if(i == stones.size()) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        // take or notTake in sum
        int take = 0;
        if(target >= stones[i]) take = stones[i] + solve(stones, i+1, target - stones[i],dp); // take and move fwd
        int notTake = solve(stones, i+1, target,dp); //move fwd
        return dp[i][target] = max(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {

        int sum = 0;
        for(auto it : stones) sum += it;
        int target = sum/2;
        vector<vector<int>> dp(stones.size()+1, vector<int>(target + 1,-1));
        for(int t = 0; t <= target; t++){
            dp[stones.size()][t] = 0;
        }
        int s1 = solve(stones,0,target,dp);
        int s2 = sum - s1;
        return abs(s1 - s2);
    }
};