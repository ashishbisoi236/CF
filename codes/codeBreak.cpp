// This takes a slightly different approach to solving this problem in a more intuitive manner
// Maintain a dp where dp[i] indicates whether the string ending at s[i - 1] can be formed using words from wordDict
// Set dp[0] as true - since any empty string can be formed without using any words from the Word Dictionary
// Now from each i where dp[i] has been set as true, check each word of the dictionary to see if that string can be formed from i. If it's possible, then set dp[i + word.size()] = true.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int i, n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(i=0; i<n; i++) {
            if(!dp[i]) continue;
            for(auto word : wordDict) {
                int len = word.size();
                if(i + len > n) continue;
                if(word == s.substr(i, len)) 
                    dp[i + len] = true;
            }
        }
        return dp[n];
    }
};