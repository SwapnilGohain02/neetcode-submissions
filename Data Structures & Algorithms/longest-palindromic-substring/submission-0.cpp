class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)    dp[i][i] = 1;
        int start = 0;
        int maxlen = 1;
        for(int i = n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j] = 1;
                    if(j-i+1 > maxlen){
                        start = i;
                        maxlen = j-i+1;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};