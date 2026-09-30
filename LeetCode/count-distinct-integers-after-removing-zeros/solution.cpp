#define ll long long
class Solution {
public:    
    long long countDistinct(long long n) {

        vector<ll> pow(16, 1);
        string s = to_string(n);
        ll ans = 0, i, m = s.length();
        for (i = 1; i <= 15; i++) pow[i] = pow[i-1] * 9; // precompute power of 9

        for (i = 1; i < m; i++) ans += pow[i]; //digits smaller than n

        for (i = 0; i < m; i++) { //digits starting with same fd as n

            if (s[i] == '0') break; //no further digits
            for (ll j = 1; j < s[i] - '0'; j++)
                ans += pow[m - i - 1]; // for each possible digit at this position, count numbers which can be made using 1-9 in remaining spots.
        }
        
        return ans + (i >= s.size());
    }
};