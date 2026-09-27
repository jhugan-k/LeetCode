class Solution {
public:
    int findMin(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i < 0) return (j + 1);
        if(j < 0) return (i + 1);
        if(dp[i][j] != -1) return dp[i][j];

        //explore all possibilities
        //match
        if(word1[i] == word2[j]) return dp[i][j] = findMin(word1,word2,i-1,j-1,dp);
        else{
            //noMatch
            int ins = 1 + findMin(word1,word2,i,j-1,dp);
            int del = 1 + findMin(word1,word2,i-1,j,dp);
            int rep = 1 + findMin(word1,word2,i-1,j-1,dp);

            return dp[i][j] = min({ins,del,rep});

        }
    }
    int minDistance(string word1, string word2){
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        //tabulation base case
        dp[0][0] = 0;
        for(int i = 1; i <= word1.size(); i++) dp[i][0] = i;
        for(int j = 1; j <= word2.size(); j++) dp[0][j] = j;
        //iteration
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                //match
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                //noMatch
                else dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j],dp[i-1][j-1]});

            }
        }
        return dp[word1.size()][word2.size()];

    }
};