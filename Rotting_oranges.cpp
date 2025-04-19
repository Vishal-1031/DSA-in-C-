class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            // Creating necessary variables and data structures
            int n = grid.size();
            int m = grid[0].size();
            // {{r,c},t}
            queue<pair<pair<int, int>, int>> q;
            // creating visited 2d array
            vector<vector<int>> vis(n, vector<int>(m, 0));
            // Now we have to fill the visited array and push starting rooten orages
            // in the queue
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 2) {
                        q.push({{i, j}, 0});
                        vis[i][j] = 2;
                    }
                    // else{
                    //     vis[i][j] = 0;
                    // }
                }
            }
    
            int tm = 0; // This will store the max time
    
            int drow[] = {-1, 0, +1, 0}; // This is our one of the main logic
            int dcol[] = {0, 1, 0, -1};  // These are arrays
            while (!q.empty()) {
                // At every iteration we are finding out some important credentials
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                // Find max time
                tm = max(tm, t);
                // After finding out credentials, pop()the front node
                q.pop();
    
                for (int i = 0; i < 4; i++) {
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];
                    // [(Check if nrow is in the bounds of row(n) && (ncol is in the
                    // bounds of columns(m))
                    //   && (it is not visited) && (it is fresh in the grid matrix)
                    //   ]
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                        q.push({{nrow, ncol}, t + 1});
                        vis[nrow][ncol] = 2;
                    }
                }
            }
            // Now after the while loop is completed we will check if any fresh oranges are left unvisited ?
            // if yes then return -1 means it is impossible to convert all the fresh oranges 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (vis[i][j] != 2 && grid[i][j] == 1) {
                        return -1;
                    }
                }
            }
            return tm;
        }
    };