class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;
        for(int i = 0; i < nums1.size(); i++){
            mpp1[nums1[i]]++;
            
        }
        for(int i = 0; i < nums2.size(); i++){
            mpp2[nums2[i]]++;
            
        }
        int ans1 = 0;
        int ans2 = 0;

        for(int i = 0; i < nums1.size(); i++){
            int ele = nums1[i];
            if(mpp2.find(nums1[i]) != mpp2.end()) ans1++;
        }

        for(int i = 0; i < nums2.size(); i++){
            int ele = nums2[i];
            if(mpp1.find(nums2[i]) != mpp1.end()) ans2++;
        }
        return {ans1,ans2};
        
    }
};