class Solution {
public:
    static bool comp(vector<int> val1, vector<int> val2) {
        return val1[1] < val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), comp);
    
    int endTime = intervals[0][1];
    int cnt = 0;
    int size = intervals.size();
    vector<int> hash(size+1, -1);
    hash[0] = 1;
    hash[1] = 1;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= endTime) {
            endTime = intervals[i][1];
            hash[i + 1] = 1;
        } else {
            cnt = cnt + 1;
        }
    }
    return cnt;
    }
};