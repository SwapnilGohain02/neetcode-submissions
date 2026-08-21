class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int currmax = 0, maxsum = INT_MIN;
        int currmin = 0, minsum = INT_MAX;
        for(auto it:nums){
            total += it;
            currmax += it;
            maxsum = max(maxsum,currmax);
            if(currmax<0){
                currmax = 0;
            }

            currmin += it;
            minsum = min(minsum,currmin);
            if(currmin>0){
                currmin = 0;
            }
        }
        if(maxsum < 0)  return maxsum;
        return max(maxsum, total - minsum);
    }
};