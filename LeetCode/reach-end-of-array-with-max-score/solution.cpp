class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        // jump greedily to next
        // for score : (j-i) * nums[i] : only factor nums[i] changes, distance is covered either way

        int lastIndex = 0;
        long long score = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[lastIndex]){
                //jump to here, add score
                score += 1LL * (i - lastIndex) * nums[lastIndex];
                lastIndex = i;
            }
        }
        if(lastIndex != nums.size()-1){
            //jump to last 
            score += (nums.size()-1 - lastIndex) * nums[lastIndex];
        }
        return score;

    }
};