#include <bits/stdc++.h>
using namespace std;

void Dijkstra(vector<vector<int>>& graph, int n, int source) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pq.push({dist[v], v});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << source << " -> " << i << " = " << dist[i] << endl;
    }
}

void Prims(vector<vector<int>>& graph, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});
    int totalCost = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        totalCost += dist[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                if (graph[u][v] < dist[v]) {
                    dist[v] = graph[u][v];
                    pq.push({dist[v], v});
                }
            }
        }
    }

    cout << "Total cost of MST : " << totalCost << endl;
}

int main() {
    int n;
    cout << "Enter no. of vertices : " << endl;
    cin >> n;

    cout << "Enter Adjacency Matrix : " << endl;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cout << "Enter source : " << endl;
    cin >> source;

    Dijkstra(graph, n, source);
    Prims(graph, n);
}
