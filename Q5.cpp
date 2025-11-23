#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> mst(n, false);
    key[0] = 0;

    for(int i = 0; i < n-1; i++) {
        int u = -1;
        for(int j = 0; j < n; j++)
            if(!mst[j] && (u == -1 || key[j] < key[u])) u = j;

        mst[u] = true;
        for(int v = 0; v < n; v++) {
            if(g[u][v] && !mst[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:" << endl;
    for(int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << "  weight: " << g[parent[i]][i] << endl;

    return 0;
}
