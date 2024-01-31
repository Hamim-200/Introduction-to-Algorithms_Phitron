#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int n, m, cnt;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool vis[N][N];

void dfs(int x, int y)
{
    vis[x][y] = true;
    cnt++;
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
    vector<int> ap_cnt;

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
                cnt = 0;
                dfs(i, j);
                ap_cnt.push_back(cnt);
            }
        }
    }

    sort(ap_cnt.begin(), ap_cnt.end());
    for (int count : ap_cnt)
    {
        cout << count << " ";
    }

    if (ap_cnt.empty())
    {
        cout << "0"<<endl;
    }

    return 0;
}
