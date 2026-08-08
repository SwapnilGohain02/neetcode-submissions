class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    vector<string> result;

    void dfs(string u) {
        while (!adj[u].empty()) {
            string v = *adj[u].begin();
            adj[u].erase(adj[u].begin());
            dfs(v);
        }

        result.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");

        reverse(result.begin(), result.end());
        return result;
    }
};