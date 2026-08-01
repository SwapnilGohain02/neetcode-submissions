class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        k = k%n;
        int j = n-k-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        i=n-k;
        j=n-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        reverse(nums.begin(),nums.end());
    }
};