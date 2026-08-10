class Solution {
public:
    vector<int>toposort(vector<vector<int>>& edges, int n){
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1,0);
        int count = 0;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=1;i<=n; i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto& iter:adj[node]){
                indegree[iter]--;
                if(indegree[iter]==0){
                    q.push(iter);
                    count++;
                }
            }
        }
        if(count != n)  return {};
        return ans;
        

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>toporow = toposort(rowConditions,k);
        vector<int>topocol = toposort(colConditions,k);

        vector<vector<int>>ans(k, vector<int>(k,0));

        if(toporow.empty() || topocol.empty()){
            return {};
        }
        vector<int>colpos(k+1);
        for(int i=0;i<k;i++){
            colpos[topocol[i]] = i;
        }

        for(int i=0;i<k;i++){
            int num = toporow[i];
            int j = colpos[num];
            ans[i][j] = num;
        }
        return ans;
    }
};