class Solution {
public:
    int prims(int v, vector<vector<pair<int,int>>>&adj){
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;

        pq.push({0,0});
        vector<bool>vis(v,false);
        int mstwt = 0;
        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            if(vis[node])   continue;
            vis[node] = true;
            mstwt += wt;
            for(auto& it : adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;
                if(!vis[adjnode]){
                    pq.push({adjwt,adjnode});
                }
            }
        }
        return mstwt;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dst = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({j,dst});
                adj[j].push_back({i,dst});
            }
        }
        return prims(n,adj);
    }
};
