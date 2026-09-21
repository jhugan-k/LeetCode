class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // take mod of all
        // possible sums:
        // 1.1.1, 2.2.2, 1.2.0, 0.0.0
        // find 3 biggest for 1,2,0 remainder
        // compare arrangemenets
        // sort descending and store first 3 value found for each remainder 
        vector<int> rem1;
        vector<int> rem2;
        vector<int> rem0;
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i = 0; i < nums.size(); i++){
            int rem = nums[i] % 3;
            if(rem == 0 && rem0.size() < 3) rem0.push_back(nums[i]);
            if(rem == 1 && rem1.size() < 3) rem1.push_back(nums[i]);
            if(rem == 2 && rem2.size() < 3) rem2.push_back(nums[i]);
            if(rem1.size() == 3 && rem2.size() == 3 && rem0.size() == 3) break; // early break
            
        }
        int sum1 = 0;
        if(rem1.size() == 3) for(auto it : rem1) sum1 += it;
        
        int sum2 = 0;
        if(rem2.size() == 3) for(auto it : rem2) sum2 += it;
        
        int sum0 = 0;
        if(rem0.size() == 3) for(auto it : rem0) sum0 += it;

        int sum120 = 0;
        if(!rem0.empty() && !rem1.empty() && !rem2.empty()) sum120 = rem0[0] + rem1[0] + rem2[0];
        
        return max({sum1, sum2, sum0, sum120});
        
        
    }
};