class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>indegree(numCourses);
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        unordered_map<int,unordered_set<int>>mp;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<bool>result(queries.size(),false);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& neigh:adj[node]){
                mp[neigh].insert(node);
                for(auto& pre:mp[node]){
                    mp[neigh].insert(pre);
                }
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        for(int i=0;i<queries.size();i++){
            int a = queries[i][0];
            int b = queries[i][1];
            bool reachable = mp[b].contains(a);
            result[i] = reachable;
        }
        return result;
    }
};