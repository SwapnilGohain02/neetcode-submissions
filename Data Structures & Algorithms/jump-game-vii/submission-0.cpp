class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int>dp(n,0);
        dp[0] = 1;
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(i - minJump >= 0){
                cnt += dp[i - minJump];
            }
            if(i - maxJump - 1 >= 0){
                cnt -= dp[i - maxJump - 1];
            }
            if(cnt > 0 && s[i] == '0'){
                dp[i] = 1;
            }
        }
        return dp[n-1]>0;
    }
};