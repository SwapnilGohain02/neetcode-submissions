class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        if(abs(target)>total)   return 0;
        if((total + target)%2)  return 0;
        int p = (total + target)/2;
        vector<vector<int>>dp(n, vector<int>(p+1,0));
        if(nums[0] == 0)    dp[0][0] = 2;
        else    dp[0][0] = 1;

        if(nums[0]!=0 && nums[0]<=p){
            dp[0][nums[0]] = 1;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=p;j++){
                int nottake = dp[i-1][j];
                int take = 0;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take + nottake;
            }
        }
        return dp[n-1][p];
    }
};
