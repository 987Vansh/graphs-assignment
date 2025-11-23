#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int u, v, w; };

int find(int x, vector<int>& parent) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

int main() {
    int n, edges;
    cin >> n >> edges;

    vector<Edge> e(edges);
    for(int i = 0; i < edges; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e.begin(), e.end(), [](Edge a, Edge b){ return a.w < b.w; });

    vector<int> parent(n);
    for(int i = 0; i < n; i++) parent[i] = i;

    cout << "Edges in MST:" << endl;
    int cost = 0;

    for(auto &ed : e) {
        int pu = find(ed.u, parent);
        int pv = find(ed.v, parent);
        if(pu != pv) {
            cout << ed.u << " - " << ed.v << "  weight:" << ed.w << endl;
            cost += ed.w;
            parent[pu] = pv;
        }
    }
    cout << "Total cost = " << cost;
    return 0;
}
