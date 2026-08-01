class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis,int n, int m,int r, int c){
        vis[r][c] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && vis[nr][nc]==0 && grid[nr][nc]=='1'){
                vis[nr][nc] = 1;
                dfs(grid,vis,n,m,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]  && grid[i][j] == '1'){
                    dfs(grid,vis,n,m,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
