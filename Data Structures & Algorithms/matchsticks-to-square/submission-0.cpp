class Solution {
public:
    bool solve(vector<int>& matchsticks, int i, vector<int>& sides, int req) {
        if(i == matchsticks.size())
            return true;

        for(int j = 0; j < 4; j++) {
            if(j > 0 && sides[j] == sides[j - 1])
                continue;

            if(sides[j] + matchsticks[i] > req)
                continue;

            sides[j] += matchsticks[i];

            if(solve(matchsticks, i + 1, sides, req))
                return true;

            sides[j] -= matchsticks[i];
            if(sides[j] == 0)
                break;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;

        for(int x : matchsticks)
            sum += x;

        if(sum % 4 != 0)
            return false;

        int req = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if(matchsticks[0] > req)
            return false;

        vector<int> sides(4, 0);

        return solve(matchsticks, 0, sides, req);
    }
};