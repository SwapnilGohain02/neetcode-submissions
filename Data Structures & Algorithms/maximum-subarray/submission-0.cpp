class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = 0;
        int ans = INT_MIN;
        for(auto it:nums){
            current += it;
            ans = max(ans,current);
            if(current<0){
                current = 0;
            }
        }
        return ans;
    }
};