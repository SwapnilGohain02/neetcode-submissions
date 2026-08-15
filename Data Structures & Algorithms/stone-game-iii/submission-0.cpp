class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int result = INT_MIN;
            result = max(result, stoneValue[i] - dp[i+1]);
            if(i+1 < n){
                result = max(result, stoneValue[i]+stoneValue[i+1]-dp[i+2]);
            }
            if(i+2 < n){
                result = max(result, stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]);
            }
            dp[i] = result;
        }
        if(dp[0] == 0)  return "Tie";
        else if(dp[0] > 0)  return "Alice";
        return "Bob";

    }
};