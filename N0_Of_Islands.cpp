class Solution {
    public:
    void bfs(int row, int col,vector<vector<char>>& grid, vector<vector<bool>>& vis , int n, int m ){
        // mark vis
        vis[row][col] = true;
        queue<pair<int,int> > q;
        q.push({row,col});
        
        int dr[] = {-1,-1,-1,0,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,0,1,-1,0,1};
        
        while ( !q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int j = 0 ; j < 9; j++){
                
                     int nr = r + dr[j];
                     int nc = c + dc[j];
                     if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
                     grid[nr][nc] == 'L' && vis[nr][nc] == false){
                         q.push({nr,nc});
                         vis[nr][nc] = true;
                        }
            }
        }
        
    }
    
  public:
    int countIslands(vector<vector<char>>& grid) {
        
        //  Find the size of grid
        int row = grid.size();
        int col = grid[0].size();
        // maintain a cnt variable 
        int cnt = 0;
        // create a visited matrix
        vector<vector<bool>> vis(row, vector<bool>(col,false));
        
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col; j++){
                if( vis[i][j] == false && grid[i][j] == 'L'){
                    bfs(i, j, grid, vis, row, col);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};