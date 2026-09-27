class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // peaks at 1,3,5,7...
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> ans(nums.size(), 0);
        int i = 1;
        int j = 0;

        for(auto it : nums){
            if(i < ans.size()){
                ans[i] = it; //place at i
                i += 2; //next placable
            }
            else{
                //place at j
                ans[j] = it;
                j += 2;
            }

        }
        nums = ans;
        return; 
        
    }
};