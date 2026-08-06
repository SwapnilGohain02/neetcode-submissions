class Solution {
public:
    vector<int>parent,rank;
    int findP(int a){
        if(parent[a] == a){
            return a;
        }
        return parent[a] = findP(parent[a]);
    }

    bool unionrank(int u, int v){
        int pu = findP(u);
        int pv = findP(v);
        if(pu == pv)    return false;
        if(rank[pu]>rank[pv]){
            parent[pv] = pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(auto it:edges){
            int a = it[0];
            int b = it[1];
            if(unionrank(a,b) == false){
                return {a,b};
            }
            
        }
        return {};
    }
};
