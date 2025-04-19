// Without connected components 
class Solution {
    public:
      bool isCycle(int V, vector<vector<int>>& edges) {
          // Code here
          queue< pair < int, int > > q;
          pair<int,int> p = make_pair(0, -1);
          q.push(p);
          vector<int> vis(V,0);
          vis[0]= 1;
          
          while(!q.empty()){
              auto fr = q.front();
              int node = fr.first;
              int parent = fr.second;
              q.pop();
              for (auto nextNode : edges[node]){
                  if(!vis[nextNode] ){
                      q.push(make_pair(nextNode, node));
                      vis[nextNode] = 1;
                  }
                  else{
                      if(nextNode != parent){
                          return true;
                      }
                  }
              }
          }
          return false ;
      }
  };

  // With connected components 
  class Solution {
    private: 
  bool detect(int src, vector<vector<int>>& adj, int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }
    
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Since Adjacency list is not given in the question we are 
        // given a vector of vector with edges, first we must make an
        // Adjacency list with it 
        vector<vector<int>> adj(V);
        // Build adjacency list from edges
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
};