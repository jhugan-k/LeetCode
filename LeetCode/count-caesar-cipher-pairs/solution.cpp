class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> mpp;
        long long count = 0;
        
        for(auto word : words){
            //map each word
            mpp[word]++;
        }
        for(auto word : words){
            //check all 26 possible variations of each word 
            // TC: word[i].length * 26 * words.length 
            // n * m * 26 == 1e5 * 26
            for(int i = 0; i < 26; i++){
                //0-25 increments
                for(auto &ch : word){
                    if(ch == 'z') ch = 'a';
                    else ch++;
                } 
                if(mpp.find(word) != mpp.end()) count += (mpp[word]); 
            }
            count--; //word also counts self once every time.
        }
        return (count / 2); //every pair is counted twice
    }
};