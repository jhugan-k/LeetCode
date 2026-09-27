class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int left = 0;
    int maxLength = 0;
    map<char, int> mpp;

    for (int right = 0; right < s.size(); right++) {
        if (mpp.find(s[right]) != mpp.end() && mpp[s[right]] >= left) {
            left = mpp[s[right]] + 1;
        }
        mpp[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

};