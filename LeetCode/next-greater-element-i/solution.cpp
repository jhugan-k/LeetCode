class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nge;
        stack<int>st;
        for(int i = nums2.size() -1; i>=0; i--){

            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            //now push in NGE   
            if(st.empty()){
                // no NGE
                nge[nums2[i]] = -1;

            }
            else{
                //push top as NGE
                nge[nums2[i]] = st.top();
            }
            st.push(nums2[i]);

        }
        //now we have all NGEs in map.
        vector<int>ans;
        for(int num : nums1){
            ans.push_back(nge[num]);
        }
        return ans;
    }
    
};