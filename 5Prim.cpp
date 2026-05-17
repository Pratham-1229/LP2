#include<bits/stdc++.h>
using namespace std;

void prims(vector<vector<int>>& graph, int n)
{
    vector<int> dist(n, INT_MAX);

    vector<bool> visited(n, false);

    dist[0] = 0;

    int totalCost = 0;

    // Repeat for all vertices
    for(int count=0; count<n; count++)
    {
        int u = -1;

        // Find minimum distance vertex
        for(int i=0; i<n; i++)
        {
            if(visited[i] == false)
            {
                if(u == -1 || dist[i] < dist[u])
                {
                    u = i;
                }
            }
        }

        // Mark as visited
        visited[u] = true;

        // Add cost
        totalCost += dist[u];
        
        // Update neighbours
        for(int v=0; v<n; v++)
        {
            if(graph[u][v] != 0 && visited[v] == false)
            {
                if(graph[u][v] < dist[v])
                {
                    dist[v] = graph[u][v];
                }
            }
        }
    }

    cout << "\nMinimum Spanning Tree Cost = "
         << totalCost << endl;
}

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> graph[i][j];
        }
    }

    prims(graph, n);

    return 0;
}
