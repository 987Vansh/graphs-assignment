#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for(int x : adj[node]) {
        if(!visited[x]) dfs(x, adj, visited);
    }
}

int main() {
    int n, edges;
    cin >> n >> edges;

    vector<vector<int>> adj(n);
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int start;
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start, adj, visited);

    return 0;
}
