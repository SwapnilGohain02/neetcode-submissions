class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int x = 0;
        for(auto n : nums){
            x |= n;
        }
        return x * (1 << nums.size()-1);
    }
};