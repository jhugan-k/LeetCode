class Solution {
public:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    // choices: skip, take in sub1 or take in sub2. 
    // explore all choices until i>= size. track sub1 and sub2.
    // if i >= size: check both subs for palindrome. if palindrome, return product len. if not palindrome, return 0.
    int solve(int i, string sub1, string sub2, string &s){
        if(i >= s.size()){
            if(isPalindrome(sub1) && isPalindrome(sub2)){
                return (sub1.size() * sub2.size());
            }
            else return 0; //not palindrome
        }
        int skip = solve(i+1, sub1, sub2, s);
        int take1 = solve(i+1, sub1 + s[i], sub2, s);
        int take2 = solve(i+1, sub1, sub2 + s[i], s);
        return max({skip, take1, take2});
    }

    int maxProduct(string s) {
        return solve(0, "", "", s);

    }
};