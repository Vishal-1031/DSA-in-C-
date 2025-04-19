class Solution {
    public:
        void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr,
                 int sc, int initialColor, int newColor) {
    
            ans[sr][sc] = newColor;
    
            int n = image.size();
            int m = image[0].size();
    
            int drow[] = {-1, 0, +1, 0};
            int dcol[] = {0, +1, 0, -1};
    
            for (int i = 0; i < 4; i++) {
                int nr = sr + drow[i];
                int nc = sc + dcol[i];
    
                if (nr < n && nr >= 0 && nc >= 0 && nc < m &&
                    image[nr][nc] == initialColor && ans[nr][nc] != newColor)  {
                    dfs(image, ans, nr, nc, initialColor, newColor);
                }
            }
        }
    
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                      int color) {
    
            vector<vector<int>> ans = image;
            int newColor = color;
            int initialColor = image[sr][sc];
            dfs(image, ans, sr, sc, initialColor, newColor);
            return ans;
        }
    };