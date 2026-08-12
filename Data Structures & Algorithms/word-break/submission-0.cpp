class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto it:wordDict){
            mp[it]++;
        }
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[n] = true;

        for(int i=n-1;i>=0;i--){
            for(int l=1;l<=n-i;l++){
                string temp = s.substr(i,l);
                if(mp.count(temp) && dp[i+l]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};