class Solution {
public:
    int n,m;
    int helper(vector<vector<int>>& mat, int i, int j,vector<vector<int>>&dp){
        if(dp[i][j] != -1)  return dp[i][j];
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        int ans = 1;
        for(int k=0;k<4;k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr>=0 && nc>=0 && nc<m && nr<n && mat[i][j]<mat[nr][nc]){
                ans = max(ans, 1 + helper(mat,nr,nc,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int maxi = 1;
        vector<vector<int>>dp(n, vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ans = helper(matrix,i,j,dp);
                maxi = max(maxi,ans);
            }
        }
        return maxi;
    }
};
