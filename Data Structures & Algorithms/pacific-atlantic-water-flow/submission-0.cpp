class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>ispac(n,vector<int>(m,0)), isatl(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            ispac[i][0] = 1;
        }

        for (int j = 0; j < m; j++) {
            ispac[0][j] = 1;
        }

        for (int i = 0; i < n; i++) {
            isatl[i][m - 1] = 1;
        }

        for (int j = 0; j < m; j++) {
            isatl[n - 1][j] = 1;
        }

        queue<pair<int,int>>q1,q2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isatl[i][j]){
                    q2.push({i,j});
                }
                if(ispac[i][j]){
                    q1.push({i,j});
                }
            }
        }
        while(!q1.empty()){
            int r = q1.front().first;
            int c = q1.front().second;
            q1.pop();
            int dr[] = {0,-1,0,1};
            int dc[] = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc<m && nc>=0 && ispac[nr][nc] == 0){
                    int height = heights[r][c] - heights[nr][nc];
                    if(height<=0){
                        q1.push({nr,nc});
                        ispac[nr][nc] = 1;
                    }

                }
            }
        }

        while(!q2.empty()){
            int r = q2.front().first;
            int c = q2.front().second;
            q2.pop();
            int dr[] = {0,-1,0,1};
            int dc[] = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc<m && nc>=0 && isatl[nr][nc]==0){
                    int height = heights[r][c] - heights[nr][nc];
                    if(height<=0){
                        isatl[nr][nc] = 1;
                        q2.push({nr,nc});
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ispac[i][j] && isatl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
