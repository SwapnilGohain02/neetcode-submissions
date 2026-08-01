class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int l=0,r=n-1;
        int boat = 0;
        sort(people.begin(),people.end());
        while(l<=r){
            int wt = people[l] + people[r];
            if(wt>limit){
                boat++;
                r--;
            }
            else if(wt==limit){
                boat++;
                l++;
                r--;
            }
            else{
                boat++;
                l++;
                r--;
            }
        }
        return boat;
    }
};