class Solution {
public:
    int minRotations(int n, string s) {
        // cost within suffix staYS same 
        // only compare start and end 
        int base = 0;
        int curr = 0;
        
        for(int i = 0; i < s.size(); i++){
            int digit = s[i] - '0';
            if(curr == digit) continue;
            else{
                int diff = abs(curr - digit);
                int alt = 10 - diff;
                base += min(diff, alt); 
                curr = digit;
            }
        }
        //now at each k, try reversing : last element becomes the transition. 
        int ans = base;
        
        for(int k = 1; k < s.size()-1; k++){
            int start = s[k] - '0';
            int end = s[s.size()-1] - '0';
            // swap end and start  
            int num = s[k-1] - '0'; 
            //check diff 
            int diff = abs(num - start);
            diff = min(diff, 10 - diff);
            int newDiff = abs(num - end);
            newDiff = min(newDiff, 10 - newDiff);
            
            if(newDiff < diff) ans = min(ans, base - abs(newDiff - diff));
            
        }
        //also check whole-string reversal
        reverse(s.begin(), s.end());
        int newBase = 0;
        curr = 0; 
        for(int i = 0; i < s.size(); i++){
            int digit = s[i] - '0';
            if(curr == digit) continue;
            else{
                int diff = abs(curr - digit);
                int alt = 10 - diff;
                newBase += min(diff, alt); 
                curr = digit;
            }
        }
        ans = min(ans, newBase);
        return ans;
    }
};