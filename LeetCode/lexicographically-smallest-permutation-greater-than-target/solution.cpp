class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char, int> mpp;

        for(char c : s)
            mpp[c]++;

        string ans;

        for(int i = 0; i < target.size(); i++) {
            char c = target[i];

            // If we can make this position bigger,
            // remember this position as a possible pivot.
            if(mpp.find(c) != mpp.end()) {
                ans += c;
                mpp[c]--;

                if(mpp[c] == 0)
                    mpp.erase(c);
            }
            else {
                break;
            }
        }

        // Go backwards and try to make one position bigger
        for(int i = ans.size(); i >= 0; i--) {

            if(i < target.size()) {
                char c = target[i];

                auto it = mpp.upper_bound(c);

                if(it != mpp.end()) {
                    string res = target.substr(0, i);

                    res += it->first;
                    mpp[it->first]--;

                    for(auto p : mpp) {
                        for(int j = 0; j < p.second; j++)
                            res += p.first;
                    }

                    return res;
                }
            }

            // Undo the character at i-1
            if(i > 0) {
                mpp[ans[i - 1]]++;
            }
        }

        return "";
    }
};