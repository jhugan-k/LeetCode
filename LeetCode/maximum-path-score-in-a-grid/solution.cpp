class Solution {
public:
    // explore paths starting from 0,0 
    // check right and bottom
    // if 0: branch without inc score
    // if 1: check cost < k, branch, score+1, cost+1.
    // if 2: check cost < k. branch, score+2, cost+1.
    // if reach m-1, n-1: return 0.
    // take max of branch scores.

    bool reachedEnd = false;
    
    int solve(int i, int j, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &dp){
        if(i == grid.size()-1 && j == grid[0].size()-1){
            reachedEnd = true;
            return dp[i][j][k] = 0;
        } 
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        int m = grid.size();
        int n = grid[0].size();
        //check right score
        int right = -1e9;
        if(i+1 < m){
            //right element exists, no cost
            if(grid[i+1][j] == 0){
                right = max(right, solve(i+1, j, grid, k,dp));
            }
            else if(grid[i+1][j] == 1 && k > 0){ //check cost
                right = max(right, 1 + solve(i+1, j, grid, k-1,dp));
            }
            else if(k > 0){ // 2
                right = max(right, 2 + solve(i+1, j, grid, k-1,dp));
            }
        }
        int down = -1e9;
        if(j+1 < n){
            if(grid[i][j+1] == 0){
                // move without cost
                down = max(down, solve(i, j+1, grid, k,dp));
            }
            else if(grid[i][j+1] == 1 && k > 0){
                //move with cost
                down = max(down, 1 + solve(i, j+1, grid, k-1,dp));
            }
            else if(k > 0){
                //2, move with cost
                down = max(down, 2 + solve(i,j+1,  grid, k-1,dp));
            }
        }
        return dp[i][j][k] = max(right, down);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size()+1, vector<vector<int>>(grid[0].size()+1, vector<int>(k+1, -1)));
        int ans = solve(0,0,grid,k,dp);
        if(reachedEnd) return ans;
        else return -1;
    }
};