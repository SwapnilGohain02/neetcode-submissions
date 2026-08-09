class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>>adj;
        unordered_map<char,int>indegree;
        for(auto it:words){
            for(auto iter:it){
                indegree[iter] = 0;
            }
        }


        for(int i=0; i<words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            int len = min(s1.size(),s2.size());
            int j = 0;
            while(j<len && s1[j] == s2[j]){
                j++;
            }

            if(j==len && s1.size()>s2.size()){
                return "";
            }

            if(j<len){
                char u = s1[j];
                char v = s2[j];
                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        queue<char>q;
        for(auto& [ch,deg]:indegree){
            if(deg == 0){
                q.push(ch);
            }
        }
        string ans = "";
        while(!q.empty()){
            char c = q.front();
            q.pop();
            ans += c;
            for(auto& n : adj[c]){
                indegree[n]--;
                if(indegree[n]==0){
                    q.push(n);
                }
            }
        }
        if(ans.size() != indegree.size()){
            return "";

        }

        return ans;
    }
};
