class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int ans = -1;
        int high = nums.size() -1;
        int mid = 0;

        while(low <= high){
            mid = low + (high - low)/2;

            if(target == nums[mid]){
                return mid;
            }

            if(nums[mid] >=nums[low]){
                //left half is sorted.
                if(target >= nums[low] && target <= nums[mid])
                //target is inside left half
                high = mid - 1;
                else{
                    //target is in right half 
                    low = mid + 1;
                }
            }
            else{
                //right half is sorted.
                if(target >= nums[mid] && target <= nums[high]){
                    //target is in right half.
                    low = mid + 1;
                }
                else{
                    //target is in left half.
                    high = mid - 1;
                }

            }
        
        }
        return -1;
    }
};