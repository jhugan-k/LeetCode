class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int currMax = 0;
        int ans = 0;

        for(int i = 0; i < weight.size(); i++){
            currMax = max(currMax, weight[i]);
            //check if box can end here 
            int curr = weight[i];
            if(weight[i] < currMax){
                //end
                ans++; 
                currMax = 0;
            }
        }
        return ans;
    }
};