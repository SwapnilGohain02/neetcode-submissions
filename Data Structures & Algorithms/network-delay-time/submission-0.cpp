class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int>dists(n+1,INT_MAX);
        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v,t});
        }

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,k});
        dists[k] = 0;
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            int dist = f.first;;
            int node = f.second;
            if(dist > dists[node])
                continue;
            for(auto iter:adj[node]){
                int edjw = iter.second;
                int adjnode = iter.first;
                if(edjw+dist<dists[adjnode]){
                    dists[adjnode] = edjw+dist;
                    pq.push({dist+edjw,adjnode});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dists[i]==INT_MAX)   return -1;
            ans = max(ans,dists[i]);
        }
        return ans;
    }
};
