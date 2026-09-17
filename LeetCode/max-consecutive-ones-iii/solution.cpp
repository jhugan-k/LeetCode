class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int firstzero = -1;
        int countzero = 0;
        int left = 0;
        int length = 0;
        int maxLength = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0) countzero++;

            while(countzero > k){
                if(nums[left] == 0) countzero--;
                left++;
            }
            length = i - left + 1;
            maxLength = max(length, maxLength);
        
        }
        return maxLength;
    }
};