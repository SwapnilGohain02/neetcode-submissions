class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for(int i=0;i<stones.size();i++){
            total += stones[i];
        }
        vector<vector<bool>>dp(n+1, vector<bool>(total + 1,false));
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            int curr = stones[i-1];
            for(int j=0;j<=total;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=curr){
                    dp[i][j] = dp[i][j] || dp[i-1][j-curr];
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<=total/2;i++){
            if(dp[n][i]){
                int j = total - i;
                ans = min(ans,abs(i-j));
            }
        }
        return ans;
    }
};