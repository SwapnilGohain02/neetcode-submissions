class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        if(sum % 2) return false;
        int target = sum/2;
        vector<vector<bool>>dp(n+1, vector<bool>(target+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0] = true;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                bool not_take = dp[i-1][j];
                bool take = false;
                if(nums[i-1]<=j){
                    take = dp[i-1][j-nums[i-1]];
                }
                dp[i][j] = take || not_take;
            }
        }
        return dp[n][target];
    }
};
