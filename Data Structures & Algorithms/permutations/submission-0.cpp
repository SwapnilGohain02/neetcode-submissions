class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>& used, vector<int>& temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i] == 1)    continue;
            used[i] = 1;
            temp.push_back(nums[i]);
            solve(nums,used,temp);
            temp.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>used(nums.size(),0);
        vector<int>temp;
        solve(nums,used,temp);
        return ans;
    }
};