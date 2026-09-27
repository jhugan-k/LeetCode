class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        // for each num: 
        // convert to string 
        // reverse string 
        // stoi 
        // = get reversed num
        // check if reversd num in map
        // if yes, take abs and compare with global min
        // put in map
        // since want minimum dist between index, only store latest index of each num
        unordered_map<int,int> mpp;
        int ans = 1e9;
        
        for(int i = nums.size()-1; i >= 0; i--){
            // get reverse
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int rev = stoi(s);
            if(mpp.find(rev) != mpp.end()){
                //reverse exists. get abs
                int revIndex = mpp[rev];
                int diff = abs(i - mpp[rev]);
                ans = min(ans, diff);
            }
            //push in map
            mpp[nums[i]] = i;
            
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};