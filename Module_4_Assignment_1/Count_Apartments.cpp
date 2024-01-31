#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int n, m, cnt;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool vis[N][N];

void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int dx = x + d[i].first;
        int dy = y + d[i].second;

        if (0 <= dx && dx < n && 0 <= dy && dy < m && !vis[dx][dy] == true)
        {
            dfs(dx, dy);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            vis[i][j] = (c == '#');
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}