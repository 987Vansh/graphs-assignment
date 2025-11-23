#include <iostream>
using namespace std;

int main() {
    int n, edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    int adj[n][n] = {0};

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << "Adjacency Matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }

    int vtx;
    cout << "Enter vertex to find degree: ";
    cin >> vtx;

    int degree = 0;
    for(int j = 0; j < n; j++) if(adj[vtx][j]) degree++;
    cout << "Degree of vertex " << vtx << " = " << degree << endl;

    cout << "Adjacent vertices of " << vtx << ": ";
    for(int j = 0; j < n; j++) if(adj[vtx][j]) cout << j << " ";

    return 0;
}
