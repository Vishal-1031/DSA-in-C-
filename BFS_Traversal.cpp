#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> bfs(vector<int> adj[],int n){
    vector<int> vis(n,0);
    vector<int> ans;
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    while(!q.empty()){

        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(vis[it] == 0){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;

}