class Solution {
    public : 
    bool dfs (int node, int parent, vector<int> adj[], vector<int>& vis){
       
        // Mark node as 1 in the vis 
        vis[node] = 1;
            
            for(auto adjacentNode : adj[node]){
            if( !vis[adjacentNode] ){ // if adjacentNode is not visited 
                bool ans = dfs(adjacentNode,node,adj,vis);
                if(ans == true) // if ans by any chance returns true then you have cycle
                return true;
            }
            // If it is previously visited and is not a parent then 
            else if(adjacentNode != parent)
                return true;
            }
            return false;
        }
    public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // create adjacency matrix 
        vector<int> adj[V];
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Create visited array, size = V sinze starting from 0
        vector<int> vis(V,0);
        for(int i = 0 ; i < V; i++ ){
            int parent = -1;
            if(!vis[i]){
                bool ans = dfs(i, parent, adj, vis);
                if(ans == true)
                return true;
            }
        }
        return false;
    }
};