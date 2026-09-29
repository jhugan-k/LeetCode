class Solution {
public:

    int arrMax(vector<int> &nums){
        int maxi = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }
        return maxi;
    }

    int arrSum(vector<int>& nums){
        int sum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }

    int isValidSolution(vector<int>& nums, int k, int mid){
        int subcount = 1;
        int csum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(csum + nums[i] <= mid){
            //addable
            csum += nums[i];
            }
            else{
                //cannot add without exceeding current max
                //move to next subarray and reset csum
                subcount++;
                if(subcount > k){
                    //early exit
                    return 0;
                }
                csum = nums[i];
            }

        
        }
        if(subcount <= k){
            return 1;
        }
        else{
            return 0;
        }
    }

    int splitArray(vector<int>& nums, int k) {
        //similar to pages problem
       int high = arrSum(nums);
       int low = arrMax(nums);
       int mid = 0;
       int ans = 0;

       if(k > nums.size()){
        return -1;
       }
        
       while(low <= high){
        mid = low + (high - low)/2;

        if(isValidSolution(nums,k,mid) == 1){
            //valid solution. try to minimise
            ans = mid;
            high = mid - 1;
        }
        else{
            //find solution
            low = mid + 1;
        }

       }
       return ans;


    }
};