class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st; 
        vector<int>ans(nums.size(),0);

        for(int i = nums.size() -1; i>=0; i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                //after setting -1, check from left side if there is no greater element
                ans[i] = -1;
                for(int k = 0; k<i; k++){
                    if(nums[k] > nums[i]){
                        //next greater element exists
                        ans[i] = nums[k];
                        break;
                    }
                }
                
            }
            else{
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};