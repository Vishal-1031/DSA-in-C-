class Solution {
    public: 
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
    vector<vector<int>>& ans, queue<pair<pair<int, int>, int>>& q){
        
        int n = grid.size();
        int m = grid[0].size();
        
        int drow[] = {-1, 0, 1,0};
        int dcol[] = {0, 1, 0, -1};
        
        
        while(!q.empty()){
            
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        
        for(int j = 0; j < 4; j++){
            int nr = r + drow[j];
            int nc = c + dcol[j];
            if(nr < n && nr >= 0 && nc >= 0 && nc < m && 
            vis[nr][nc] == 0 && grid[nr][nc] == 0){
                q.push({{nr,nc},t + 1});
                vis[nr][nc] = 1;
                ans[nr][nc] = t + 1;
            }
        }
        
        }
        
        
    }
    
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int> >q ;
        
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == 1)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }
        
        bfs(grid, vis, ans, q );
        return ans;
        
    }
};