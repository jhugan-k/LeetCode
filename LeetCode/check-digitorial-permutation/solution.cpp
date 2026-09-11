class Solution {
public:
    // find factorial sum 
    // check if facSum can be created using digits of n. 
    vector<int> dp = vector<int>(10, -1);
    int factorial(int k){
        if(k == 0) return 1;
        if(k == 1) return 1;
        if(k == 2) return 2;
        if(dp[k] != -1) return dp[k];
        else return dp[k]  = (k * factorial(k-1));
    }

    bool isDigitorialPermutation(int n) {
        unordered_map<int,int> mpp;
        long long factSum = 0;

        while(n > 9) {
            //n is double digited
            int digit = n % 10;
            n = n / 10;
            factSum += factorial(digit);
            mpp[digit]++;
        }
        mpp[n]++; //single digit n
        factSum += factorial(n);

        //compare digits of factSum with digits of N.
        while(factSum > 9){
            int digit = factSum % 10;
            factSum = factSum / 10;
            if(mpp.find(digit) == mpp.end()) return false; //digit exists in factSum but not in n.
            else{ // place digit
                mpp[digit]--;
                if(mpp[digit] == 0) mpp.erase(digit);
            }
        }
        //check last digit of factSum
        if(mpp.find(factSum) == mpp.end()) return false;
        else{
            mpp[factSum]--;
            if(mpp[factSum] == 0) mpp.erase(factSum);
        }
        if(mpp.empty()) return true; //all digits used
        else return false;
    }
};