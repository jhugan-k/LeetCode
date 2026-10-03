class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        // use prefix sums
        // in map: store (val, sum upto val)
        // while traversing again, calculate counterpart prefix sum, then find pair (val, counterpart) and add its freq to total. 

        //prefix sum: sum of elements before current.
        // prefix[i+1]: sum of elements upto current
        int n = capacity.size();
        vector<int> nums = capacity;

        vector<long long> prefix(n+1, 0);
        for(int i = 0; i < capacity.size(); i++){
            prefix[i+1] = prefix[i] + nums[i]; // sum before cuurrent
        }
        map<pair<int,long long>, long long> mpp; // {element, sumUpto}, count
        long long ans = 0;

        for(int r = 2; r < nums.size(); r++){
            int l = r - 2; //max l. previous l are tracked in previous iterations.
            mpp[{nums[l], prefix[l+1]}]++;
            //now check how many valid l
            long long reqPrefix = prefix[r] - nums[r]; 
            ans += mpp[{nums[r], reqPrefix}];
        }

        return ans;
        
    }
};