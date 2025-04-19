class Solution {
    public : 
    void dfss(int node, vector<vector<int>>& adj, int vis[], vector<int>& ls){
        vis[node] = 1;
        ls.push_back(node);
        // traverse all its neighbours
        for(auto it : adj[node]){
            if(!vis[it]){
                dfss(it,adj,vis,ls);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int> >& adj) {
        int vis[1000] = {0};
        int start = 0;
        vector<int> ls;
        dfss(start,adj, vis, ls);
        return ls;
    }
};