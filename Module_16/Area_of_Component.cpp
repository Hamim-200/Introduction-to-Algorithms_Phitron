#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y, int &area)
{
    visited[x][y] = true;
    area++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '.')
        {
            dfs(grid, visited, nx, ny, area);
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int minArea = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                int area = 0;
                dfs(grid, visited, i, j, area);
                minArea = min(minArea, area);
            }
        }
    }

    if (minArea == INT_MAX)
        cout << -1 << endl;
    else
        cout << minArea << endl;

    return 0;
}
