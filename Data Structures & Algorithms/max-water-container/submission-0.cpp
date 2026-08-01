class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int maxwater = 0;
        while(l<r){
            int water = (r-l)*(min(heights[l],heights[r]));
            maxwater = max(water,maxwater);
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxwater;
    }
};
