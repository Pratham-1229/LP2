#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    int g, h, f;
};

int heuristic(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

void aStar(vector<vector<int>>& grid,int sx, int sy,int gx, int gy)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n,vector<bool>(m, false));

    priority_queue<
        pair<int, Node>,
        vector<pair<int, Node>>,
        greater<pair<int, Node>>
    > pq;

    Node start;

    start.x = sx;
    start.y = sy;

    start.g = 0;

    start.h = heuristic(sx, sy, gx, gy);

    start.f = start.g + start.h;

    pq.push({start.f, start});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    cout << "\nPath:\n";

    while(!pq.empty())
    {
        Node current = pq.top().second;

        pq.pop();

        int x = current.x;
        int y = current.y;

        if(visited[x][y])
        {
            continue;
        }

        visited[x][y] = true;

        cout << "(" << x << "," << y << ") ";

        // Goal reached
        if(x == gx && y == gy)
        {
            cout << "\nGoal Reached";
            return;
        }

        // Explore neighbours
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 &&
               nx < n && ny < m &&
               grid[nx][ny] == 0 &&
               !visited[nx][ny])
            {
                Node next;

                next.x = nx;
                next.y = ny;

                next.g = current.g + 1;

                next.h = heuristic(nx, ny, gx, gy);

                next.f = next.g + next.h;

                pq.push({next.f, next});
            }
        }
    }

    cout << "\nNo Path Found";
}

int main()
{
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n,
    vector<int>(m));

    cout << "\nEnter Grid:\n";
    cout << "0 = Free Cell\n";
    cout << "1 = Blocked Cell\n\n";

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int sx, sy, gx, gy;

    cout << "\nEnter Start Position: ";
    cin >> sx >> sy;

    cout << "Enter Goal Position: ";
    cin >> gx >> gy;

    aStar(grid, sx, sy, gx, gy);

    return 0;
}