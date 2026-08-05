class Solution {
public:
    void fillneighbors(queue<string>& q, unordered_set<string>&st, string curr){

        for(int i=0;i<4;i++){
            char ch = curr[i];
            char inc = ch == '9'?'0':ch+1;
            curr[i] = inc;
            if(st.find(curr)==st.end()){
                st.insert(curr);
                q.push(curr);
            }

            char dec = ch == '0'?'9':ch-1;
            curr[i] = dec;
            if(st.find(curr)==st.end()){
                st.insert(curr);
                q.push(curr);
            }
            curr[i] = ch;
        }

    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        string start = "0000";
        if(st.find(start)!=st.end())    return -1;
        queue<string>q;
        q.push(start);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == target){
                    return level;
                }

                fillneighbors(q,st,curr);
            }
            level++;
        }
        return -1;
    }
};