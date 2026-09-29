class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> ans;
        // total - 2 * (negSum) = target.
        // netSum = total - target / 2;
        long long totalSum = 1LL * (1LL * n * (n+1)) / 2;
        
        long long negSum = (totalSum - target) / 2;
        if(target > totalSum || target < -totalSum || (totalSum - target) % 2 != 0) return {};

        //make negSum using greedy selection
        
        for(int i = n; i > 0; i--){
            //take i
            if(negSum >= i){
                negSum -= i;
                ans.push_back(-i);
            }
            else{
                // can't take i, wait for smaller number
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};