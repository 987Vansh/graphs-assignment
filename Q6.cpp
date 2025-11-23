#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, start;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    cin >> start;
    vector<int> dist(n, INT_MAX), vis(n, false);
    dist[start] = 0;

    for(int i = 0; i < n - 1; i++) {
        int u = -1;
        for(int j = 0; j < n; j++)
            if(!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;

        vis[u] = true;

        for(int v = 0; v < n; v++)
            if(g[u][v] && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }

    for(int i = 0; i < n; i++)
        cout << "Distance to " << i << " = " << dist[i] << endl;

    return 0;
}
