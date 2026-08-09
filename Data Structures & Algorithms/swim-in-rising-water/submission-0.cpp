class Solution {
public:
    int n;
    bool possible(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& vis, int time){
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        if(r<0 || r>=n || c<0 || c>=n || vis[r][c] || grid[r][c]>time){
            return false;
        }
        if(r == n-1 && c == n-1)    return true;

        vis[r][c] = 1;

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(possible(grid,nr,nc,vis,time)){
                return true;
            }
        }
        return false;

    }
    int swimInWater(vector<vector<int>>& grid) {
        int result = 0;
        n = grid.size();
        int l = 0;
        int r = n*n - 1;
        while(l <= r){
            vector<vector<int>>vis(n,vector<int>(n,0));
            int mid = l + (r-l)/2;
            if(possible(grid,0,0,vis,mid)){
                r = mid-1;
                result = mid;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};