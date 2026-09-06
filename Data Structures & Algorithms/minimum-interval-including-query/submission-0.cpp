class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>>qs;
        for(int i=0;i<queries.size();i++){
            qs.push_back({queries[i],i});
        }
        vector<int>ans(queries.size(),-1);
        sort(qs.begin(),qs.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        int i = 0;
        for(auto [q, index] : qs){
            while(i < intervals.size() && intervals[i][0] <= q){
                int size = intervals[i][1] -intervals[i][0] + 1;
                pq.push({size,intervals[i][1]});
                i++;
            }

            while(!pq.empty() && pq.top().second < q){
                pq.pop();
            }

            if(!pq.empty()){
                ans[index] = pq.top().first;
            }
        }
        return ans;
        
    }
};