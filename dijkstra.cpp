#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

const int INF = 1e9;

int nodes, edges;

vector<pair<int, int>> adj_list[N];

int d[N];

void dijkstra(int src) {
    for(int i = 1; i <= nodes; i++){
        d[i] = INF;
    }
    d[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int selected_node = q.front();
        q.pop();
        for(auto adj_entry: adj_list[selected_node]){
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;

            if(d[selected_node] + edge_cost < d[adj_node]){
                d[adj_node] = d[selected_node] + edge_cost;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    int src = 1;
    dijkstra(src);

    for(int i = 1; i <= nodes; i++){
        cout << d[i] << ' ';
    }
    cout << '\n';
    return 0;
}