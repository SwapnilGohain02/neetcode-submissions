class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int>R, D;
        for(int i=0;i<n;i++){
            if(senate[i] == 'R'){
                R.push(i);
            }else{
                D.push(i);
            }
        }

        while(!R.empty() && !D.empty()){
            int r = R.front();
            R.pop();

            int d = D.front();
            D.pop();
            if(r < d){
                R.push(r + n);
            }
            else{
                D.push(d + n);
            }
        }

        if(R.empty())   return "Dire";
        return "Radiant";
    }
};