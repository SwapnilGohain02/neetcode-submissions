class Solution {
public:
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto iter = q.front();
            q.pop();
            int r = iter.first;
            int c = iter.second;
            int dr[] = {0,-1,0,1};
            int dc[] = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<m && nr>=0 && nc>=0 && nc<n && grid[nr][nc]==INF){
                    grid[nr][nc] = grid[r][c]+1;
                    q.push({nr,nc});

                }
            }
        }
    }
};
