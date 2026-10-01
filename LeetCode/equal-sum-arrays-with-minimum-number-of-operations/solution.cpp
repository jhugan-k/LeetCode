class Solution {
public:
    // sort both
    // pointer on each: i and j
    // either decrease bigger or increase smaller 
    // calculate value gained from each. 
    // i to bigger sum, j to smaller sum 

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sum1 = 0;
        int sum2 = 0;
        for(auto it : nums1) sum1 += it;
        for(auto it : nums2) sum2 += it;

        int i = 0;
        int j = 0;
        if(sum1 == sum2) return 0;
        if(sum1 > sum2){
            // 1 is bigger. i on 1. select big elements to reduce first.
            i = nums1.size()-1;
        }
        else{
            // 2 is bigger. i on 2. select big elements to reduce first;
            i = nums2.size()-1;
        }
        int ops = 0;

        if(sum1 > sum2){
            //initial 
            while(sum1 > sum2){
                // 1 is originally bigger
                // reduce i or increase j

                if(i < 0 && j >= nums2.size()){
                    // out of bounds, no more indexes to use, but sums still not equal. 
                    return -1;
                }

                int reduce = 0; 
                if(i >= 0) reduce = nums1[i] - 1;

                int increase = 0;
                if(j < nums2.size()) increase = 6 - nums2[j];
                if(reduce == 0 && increase == 0){
                    //can't do anything either side
                    i--;
                    j++;
                }
                

                if(reduce > increase){
                    //use reduce
                    ops++;
                    sum1 -= reduce;
                    i--;
                }
                else{
                    //use increase
                    ops++;
                    sum2 += increase;
                    j++;
                }
            }
            return ops;
        }
        else{
            //initial 
            while(sum2 > sum1){
                // 2 is originally bigger
                // i is on 2, j is on 1

                if(i < 0 && j >= nums1.size()){
                    // out of bounds, no more indexes to use, but sums still not equal. 
                    return -1;
                }

                int reduce = 0; 
                if(i >= 0) reduce = nums2[i] - 1;

                int increase = 0;
                if(j < nums1.size()) increase = 6 - nums1[j];

                if(reduce == 0 && increase == 0){
                    //can't do anything either side
                    i--;
                    j++;
                }
                

                if(reduce > increase){
                    //use reduce
                    ops++;
                    sum2 -= reduce;
                    i--;
                }
                else{
                    //use increase
                    ops++;
                    sum1 += increase;
                    j++;
                }

            }
            return ops;
        }

    }
};