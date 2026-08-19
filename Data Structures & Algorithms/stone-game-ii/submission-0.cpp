class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int person, int i, int M, vector<int>& piles ){
        if(i >= n)  return 0;
        if(dp[i][person][M]!= -1)   return dp[i][person][M];
        int stones = 0;
        int result;
        if(person == 1){
            result = -1;
        }
        else{
            result = INT_MAX;
        }
        for(int x=1;x<=min(2*M,n-i);x++){
            stones += piles[x+i-1];
            if(person == 1){
                result = max(result,stones+solve(0,i+x,max(M,x),piles));
            }
            else{
                result = min(result, solve(1,i+x,max(M,x),piles));
            }
            
        }
        return dp[i][person][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.resize(n, vector<vector<int>>(2, vector<int>(n+1,-1)));
        return solve(1,0,1, piles);
    }
};