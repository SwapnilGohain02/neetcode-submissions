class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>&vis){
        vis[node] = 1;
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;

        
    }
};
