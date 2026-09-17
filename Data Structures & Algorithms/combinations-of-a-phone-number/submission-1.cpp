class Solution {
public:
    vector<string>ans;
    void solve(int i, const string& digits, string& s,
           const vector<string>& letters){
        if(i >= digits.size()){
            ans.push_back(s);
            return;
        }
        int d = digits[i]-'0';
        for(int j=0;j<letters[d].size();j++){
            s += letters[d][j];
            solve(i+1,digits,s,letters);
            s.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")    return {};
        vector<string> letters = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
                };
        string s = "";
        solve(0,digits,s,letters);
        return ans;
    }
};