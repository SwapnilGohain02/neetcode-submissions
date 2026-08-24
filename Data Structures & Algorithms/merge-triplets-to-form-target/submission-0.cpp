class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = target[0], b = target[1], c = target[2];
        bool first = false, second = false, third = false;
        for(auto &it:triplets){
            if(it[0] > a || it[1] > b || it[2] > c) continue;

            if(it[0] == a)  first = true;
            if(it[1] == b)  second = true;
            if(it[2] == c)  third = true;
        }
        return first && second && third;
    }
};