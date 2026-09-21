class Solution {
public:
    long long minMoves(vector<int>& balance) {
        // find location of negative balance: o(n)
        // expand around nefgative balance: o(n) 
        int target = 0;
        
        for(int i = 0; i < balance.size(); i++){
            if(balance[i] < 0){
                target = i;
                break;
            }
        }
        int left = target - 1;
        int right = target + 1;
        int factor = 1; 
        long long moves = 0;
        
        // greedily take all from left and right. when finished, decrease left, increase right and increase factor
        while(balance[target] < 0){
            if(left < 0) left = balance.size()-1;
            if(right >= balance.size()) right = 0; //overflow condition
            if(left == target || right == target) return -1; // wrapped around to target
            if(abs(balance[target]) <= balance[left] || abs(balance[target]) <= balance[right]){
                //can be satisfied by left or right individually
                moves += abs(1LL * balance[target] * factor);
                return moves;
            }
            //else : can't be uniquely satisfied, need combination of both. 
            else{
                //submit left
                balance[target] += balance[left];               
                moves += abs(1LL * balance[left] * factor);
                balance[left] = 0;
                
                //check if right can satisfy now 
                if(abs(balance[target]) <= balance[right]){
                    moves += abs(1LL * balance[target] * factor);
                    return moves;
                }
                //still unsatisfied. take right, increase factor, expand R&L
                balance[target] += balance[right];
                moves += abs(1LL * balance[right] * factor);
                balance[right] = 0;
                
                right++;
                left--;
                factor++;
            }
            
        }
        return moves;
        
    }
};