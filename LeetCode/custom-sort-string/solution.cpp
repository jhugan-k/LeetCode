class Solution {
public:
    string customSortString(string order, string s) {
        // take an empty ans string 
        // first put down all leters that are present in order, and in s
        // once satisfied, put in the remaining letters of s. 
    
        unordered_map<char,int> mpp;
        
        for(auto it : s) mpp[it]++;
        
        string ans;
        
        for(auto ch : order){
            
            // check if this char appears in s
            if(mpp.find(ch) == mpp.end()) continue;
            else{
                //appears. put all occourences of ch into ans.
                while(mpp[ch] > 0){
                    ans += ch;
                    mpp[ch]--;
                }
                if(mpp[ch] == 0) mpp.erase(ch);
            }
        }
        //put remaining into ans;
        for(auto it : mpp){
            char ch = it.first;
            int freq = it.second;
            for(int i = 0; i < freq; i++){
                ans += ch;
            }
        }
        return ans;
    }
};