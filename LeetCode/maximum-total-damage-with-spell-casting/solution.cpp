class Solution {
public:
    // if we take spell with dmg x, we take all with dmg x.
    // spells are related to dmg not index. so group all together 
    // find net dmg gain from each distinct value and store it in map
    // when taking spell, we add net gain
    // dp take / not take spell on unique spell array
    // not take: dp[i-1]
    // take: dp[j] where j is the first unique element <= (power[i] - 3) bcause p[i] -1 and p[i]-2 not allow

    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        map<int,long long> gain;
        vector<int> vals;
        for(auto it : power) gain[it] += it; 
        for(auto it : gain) vals.push_back(it.first); //push distinct values in sorted order

        //dp on vals 
        vector<long long> dp(vals.size(),-1); // dp[i] = maximum dmg possible upto index i
        dp[0] = gain[vals[0]]; //best possible solution for index 0: take. 

        for(int i = 1; i < vals.size(); i++){
            //take or not take this spell
            long long notTake = dp[i-1];
            // if taking we need to find j such that j is smaler tham vals[i-2].
            // use upperbound - 1.
            int j = upper_bound(vals.begin(), vals.end(), vals[i] - 3) - vals.begin() - 1; 
            // upper bound finds last value strictly greater than val[i] - 3, then reduces index to find value  <= val[i]-3.

            long long take = gain[vals[i]];
            if(j >= 0) take += dp[j];
            dp[i] = max(take, notTake);

        }
        return dp[vals.size()-1];

        
    }
};