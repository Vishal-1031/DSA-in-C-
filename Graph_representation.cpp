// // Through Adjacency matrix 
// #include <iostream>
// using namespace std;
// int main (){
//     int n,m;
//     cin >> n >> m ;
//     int adj [n+1][n+1] ;// initialization of matrix to zero
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= n; j++) {
//             adj[i][j] = 0;
//         }
//     }
//     for(int i = 0; i < m ; i++){
//         cout << "Enter the edges " << endl;
//         int u ,v;
//         cin >> u >> v ;
//         cout << "Edge from " << u << " to " << v << endl;
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= n; j++)
//             cout << adj[i][j] << " ";
//         cout << endl;
//     }
// }

// // Through Adjacency list 
// int main(){
//     int n,m;
//     cin>> n >> m ;
//     vector<int> adj[n+1]; // this is an array of vectors 
//     for(int i = 0; i<m;i++){
//         int u ,v ;
//         cin >> u>> v ;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     return 0;
// }

// Adjacency matrix for weighted graph 
#include <iostream>
using namespace std;
int main (){
    int n,m;
    cin >> n >> m ;
    int adj [n+1][n+1] ;// initialization of matrix to zero
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            adj[i][j] = 0;
        }
    }
    for(int i = 0; i < m ; i++){
        cout << "Enter the edges " << endl;
        int u ,v, wt;
        cin >> u >> v >> wt;

        cout << "Edge from " << u << " to " << v << " and weight " << wt<< endl;
        adj[u][v] = wt;
        adj[v][u] = wt;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}