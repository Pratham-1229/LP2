#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> graph[100];
bool visited[100];
int vertices, edges;

// Function to add edge
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u); // Undirected graph
}

// Recursive DFS Function
void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor);
        }
    }
}

// BFS Function
void BFS(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "\nEnter edges (u v):\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    int start;

    cout << "\nEnter starting vertex: ";
    cin >> start;

    int choice;

    do
    {
        // Reset visited array
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }

        cout << "\n----- MENU -----\n";
        cout << "1. DFS Traversal\n";
        cout << "2. BFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nDFS Traversal: ";
                DFS(start);
                cout << endl;
                break;

            case 2:
                cout << "\nBFS Traversal: ";
                BFS(start);
                cout << endl;
                break;

            case 3:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
