class Solution {
public:
    vector<int>parent,rank;
    int findP(int a){
        if(a == parent[a]){
            return a;
        }
        return parent[a] = findP(parent[a]);
    }

    void unionrank(int u, int v){
        int pu = findP(u);
        int pv = findP(v);

        if(pu == pv)    return;
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
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    unionrank(i,mp[mail]);
                }
            }
        }

        vector<vector<string>>mergedmail(n);
        for(auto it:mp){
            string mail = it.first;
            int node = findP(it.second);
            mergedmail[node].push_back(mail);
        }


        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedmail[i].empty())   continue;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto& iter:mergedmail[i]){
                temp.push_back(iter);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};