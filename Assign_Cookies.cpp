class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            int i = 0, j = 0;
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            while (j < s.size() && i < g.size()) {//
                if (g[i] <= s[j]) {
                    i = i + 1; // conditionally age badhana hai
                }
                j = j + 1; // without any condition aage badhana hai
            }
            return i;
        }
    };