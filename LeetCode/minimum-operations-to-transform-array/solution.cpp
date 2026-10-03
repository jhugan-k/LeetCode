class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        // take target = num2[last] 
        // iterate: check range on each i 
        // if target lies in range: only append during some ops. no extra ops.
        // also track abs() of both bounds (since dosent lie in any range). 
        // if not lied in any range, abs() operations will be required extra.

        long long totalOps = 0;
        int target = nums2[nums2.size()-1];
        bool found = 0;
        int diff = 1e9;

        for(int i = 0; i < nums1.size(); i++){
            int r1 = nums1[i];
            int r2 = nums2[i];
            if(r1 > r2){
                // start r2
                if(target >= r2 && target <= r1) found = 1;
                else diff = min({diff, abs(target - r2), abs(target - r1)}); 
                
            }
            else if(r1 < r2){ //start is r1 
                if(target >= r1 && target <= r2) found = 1;
                else diff = min({diff, abs(target - r2), abs(target - r1)});
            }
            else{
                // r1 == r2
                if(target == r1) found = 1;
                else diff = min({diff, abs(target - r2), abs(target - r1)});
            }
            // abs difference will be added to total
            totalOps += abs(r1 - r2);
            
        }
        //check if found
        if(found) totalOps++;
        else totalOps += (diff + 1); //only 1 extra op if found, else 1 to append and (abs) to cover
        return totalOps;
    }
};