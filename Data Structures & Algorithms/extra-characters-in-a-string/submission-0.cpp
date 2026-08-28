class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int>dp(n+1,0);
        for(int i = n-1; i>=0; i--){
            int minextra = INT_MAX;
            string curr = "";
            for(int j = i; j<n; j++){
                curr += s[j];
                int currextra = 0;
                if(st.find(curr) == st.end()){
                    currextra = curr.size();
                }
                int remextra = dp[j+1];
                int totalextra = remextra + currextra;
                minextra = min(totalextra,minextra);
            }
            dp[i] = minextra;
        }
        return dp[0];
        
    }
};