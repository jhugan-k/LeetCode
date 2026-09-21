class Solution {
public:
    /*
    -----CLARIFYING QUESTIONS-----
    can i, j, k be negative?
    what is the range of nums[k] ?
    what is the range of size of nums? 

    -----BRUTE APPRAOCH-----
    Generate all possibilities using a triple for loop 
    time complexity: O(n3) space: O(n)

    -----BETTER APPROACH-----
    double for loop + hashMap
    Time: O(n2) space: O(n)

    -----BEST APPROACH-----

    sorting + 2P
    Time:  O(n2) space: O(1)
    > sort the array for easy increment/decrement of total sum as required
    > for each element check the array again: left and right 
    > if sum > 0: increase sum, left++ (left++ only gives better sum)
    > if sum < 0: decrease sum, right-- (right -- only gives smaller sum)
    > do this while left < right. if at any point left > right then move on to next element 
    > skip duplicates when found a triplet : while() to avoid duplicate triplets

    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; //skip duplicates

            int left = i + 1;
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                //found valid triplet 
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);

                ans.push_back(temp);
                //eliminate any duplicates
                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;
                //move to next evaluation
                left++;
                right--;

            }
            else if (sum > 0) right--;
            else left++;

            }
            
        }
        return ans;
    }
};