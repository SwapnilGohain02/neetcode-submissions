class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int, pair<int,int>>>q;
        vector<int>dists(n,INT_MAX);
        q.push({0,{src,0}});
        dists[src] = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int stops = x.first;
            int node = x.second.first;
            int dist = x.second.second;
            if(stops>k) continue;
            for(auto iter:adj[node]){
                int adjnode = iter.first;
                int edjwt = iter.second;
                if(edjwt + dist < dists[adjnode] && stops<=k){
                    dists[adjnode] = dist + edjwt;
                    q.push({stops+1,{adjnode,dist+edjwt}});
                }
            }
        }
        if(dists[dst]==INT_MAX) return -1;
        return dists[dst];
    }
};
