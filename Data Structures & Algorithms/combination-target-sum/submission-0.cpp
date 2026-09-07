class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int target, int start,
               vector<int>& temp) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int j = start; j < nums.size(); j++) {

            if (nums[j] > target)
                break;
            temp.push_back(nums[j]);
            solve(nums, target - nums[j], j, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        solve(nums, target, 0, temp);

        return ans;
    }
};