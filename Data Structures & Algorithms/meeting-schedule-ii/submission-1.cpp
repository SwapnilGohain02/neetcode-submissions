/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int>start(n), ends(n);
        for(int i=0;i<n;i++){
            start[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }

        sort(start.begin(), start.end());
        sort(ends.begin(), ends.end());

        int i = 0, j = 0;
        int rooms = 0, maxrooms = 0;
        while(i < n){
            if(start[i] < ends[j]){
                rooms++;
                maxrooms = max(maxrooms, rooms);
                i++;
            }
            else{
                rooms--;
                j++;
            }
        }
        return maxrooms;
    }
};
