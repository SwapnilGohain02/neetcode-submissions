class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, int r, int c){
        vis[r][c] = 1;
        int size = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && vis[nr][nc]==0 && grid[nr][nc]==1){
                size += dfs(grid,vis,n,m,nr,nc);
            }
        }
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxsize = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    int size = dfs(grid,vis,n,m,i,j);
                    maxsize = max(maxsize,size);
                }
            }
        }
        return maxsize;
    }
};
