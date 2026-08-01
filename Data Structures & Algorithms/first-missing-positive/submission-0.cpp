class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int corrIdx = 0;
        while(i<n){
            if(nums[i]>=1 && nums[i]<=n){
                corrIdx = nums[i]-1;
                if(nums[i] != nums[corrIdx]){
                    swap(nums[i],nums[corrIdx]);
                    continue;
                }
            }
            i++;
        }

        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};