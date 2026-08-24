class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[hand[i]]++;
        }
        while(!freq.empty()){
            int start = freq.begin()->first;
            for(int k = start; k < start+groupSize; k++){
                if(freq[k]==0){
                    return false;
                }

                freq[k]--;

                if(freq[k]==0){
                    freq.erase(k);
                }
            }
        }
        return true;
    }
};
