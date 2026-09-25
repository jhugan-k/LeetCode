class Solution {
public:
    /*
    ----CQ----
    > constraints for nums.size() and nums[i]
    > is sorted? 

    ----BRUTE----
    > generate all subarrays
    > see the number of elements in each subarray


    ----BETTER----
    > Exactly K = atMost(k) - atMost (k-1)
    > atMost(K): Use sliding window 
    > for atMost K, right - left + 1 indicates all valid subarrays with at most k distinct elements


    */

    int atMostK(vector<int> &nums, int k){
        int left = 0;
        unordered_map<int,int> mpp;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++){
            //add to map 
            mpp[nums[right]]++;
            //shrink if window is large 
            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            //add if window is valid 
            if(mpp.size() <= k){
                ans += (right - left + 1);
            }
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (atMostK(nums, k) - atMostK(nums, k-1));
    }
};