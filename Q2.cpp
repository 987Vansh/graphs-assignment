#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, edges;
    cout << "Enter vertices and edges: ";
    cin >> n >> edges;

    vector<vector<int>> adj(n);
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int x : adj[node]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return 0;
}
