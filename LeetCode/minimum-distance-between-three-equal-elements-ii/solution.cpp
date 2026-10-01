class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // couunt number - {set of indexes where appeared}
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }
        int ans = 1e9;
        
        for(auto it : mpp){
            vector<int> v = it.second;
            if(v.size() < 3) continue;
            // minimum dist will be always in consecutive indexes.
            // for each index, check it's + 2 for dist.
            for(int i = 0; i + 2 < v.size(); i++){
                int dist = 2*(abs(v[i] - v[i+2]));
                ans = min(ans, dist);
            }
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};