class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> mpp;

        for (int x : nums) {
            mpp[x]++;
        }

        int count = 0;

        for (auto it : mpp) {
            int x = it.first;

            if (k == 0) {
                if (it.second > 1)
                    count++;
            }
            else {
                if (mpp.find(x + k) != mpp.end())
                    count++;
            }
        }

        return count;
    }
};
