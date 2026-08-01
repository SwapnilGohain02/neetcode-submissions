class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
        pq.push({0,{0,0}});
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>eff(n,vector<int>(m,INT_MAX));
        eff[0][0] = 0;
        while(!pq.empty()){
            auto iter = pq.top();
            pq.pop();
            int effort = iter.first;
            int r = iter.second.first;
            int c = iter.second.second;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int edjw = abs(heights[nr][nc] - heights[r][c]);
                    int newef = max(effort,edjw);
                    if(newef < eff[nr][nc]){
                        eff[nr][nc] = newef;
                        pq.push({newef,{nr,nc}});
                    }
                }
            }
        }
        return eff[n-1][m-1];
    }
};