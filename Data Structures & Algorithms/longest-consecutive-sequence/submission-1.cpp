class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxLen = 0;
        for(int num : st){
            if(st.find(num-1)==st.end()){
                int len = 1;
                int curr = num;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};