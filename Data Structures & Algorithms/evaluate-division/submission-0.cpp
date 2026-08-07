class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string,double>>>& adj, unordered_set<string>& st, string src, string dst, double product, double& ans){
        if(st.find(src)!=st.end()){
            return;
        }
        if(src == dst){
            ans = product;
            return;
        }
        st.insert(src);

        for(auto it:adj[src]){
            string s = it.first;
            double val = it.second;
            dfs(adj,st,s,dst,product*val,ans);
        }

        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string,double>>> adj;
        for(int i=0;i<n;i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        int q = queries.size();
        vector<double>result(q);
        for(int i=0;i<q;i++){
            double product = 1;
            string src = queries[i][0];
            string dst = queries[i][1];
            double ans = -1;
            if(adj.find(src) != adj.end()){
                unordered_set<string>vis;
                dfs(adj,vis,src,dst,product,ans);
            }
            result[i] = ans;
        }
        return result;
    }
};