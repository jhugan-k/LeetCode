class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>sset;
        int longest = 0;
        for(int i = 0; i<nums.size(); i++){
            sset.insert(nums[i]);
        }
        for(auto it: sset){
            if(sset.find(it - 1)  == sset.end()){
                int length = 1;
                int x = it;
                while(sset.find(x+1) != sset.end()){
                    x = x+1;
                    length++;
                }
                longest = max(longest, length);
            }


        }
        return longest;
    
    }
};