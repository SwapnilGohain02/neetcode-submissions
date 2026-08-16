class Solution {
    int getCount(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(i<0 || amount<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        if(amount==0) return 1;
        int take=getCount(i,amount-coins[i],coins,dp);
        int notTake=getCount(i-1,amount,coins,dp);
        return dp[i][amount]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return getCount(n-1,amount,coins,dp);
    }
};
