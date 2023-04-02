// problem link -> https://codeforces.com/problemset/problem/20/C

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const long long INF = 1e18;

int n, m;

int parent[N];

vector<pair<int, int>> adj_list[N];

long long d[N];

void dijkstra(int src){
    for(int i = 1; i <= n; i++){
        d[i] = INF;
    }
    d[src] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        pair<long long, int> head = pq.top();
        pq.pop();
        int selected_node = head.second;
        for(auto adj_entry: adj_list[selected_node]){
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if(d[selected_node] + edge_cst < d[adj_node]){
                d[adj_node] = d[selected_node] + edge_cst;
                parent[adj_node] = selected_node;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    dijkstra(1);

    if(d[n] == INF){
        cout << "-1\n";
        return 0;
    }
    // cout << d[n];
    int current_node = n;
    stack<int> path_st;
    while(true){
        path_st.push(current_node);
        if(current_node == 1){
            break;
        }
        current_node = parent[current_node];
    }
    while(!path_st.empty()){
        cout << path_st.top() << ' ';
        path_st.pop();
    }
    return 0;
}