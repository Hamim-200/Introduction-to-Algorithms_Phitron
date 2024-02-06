#include <bits/stdc++.h>
using namespace std;

int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool validate(int i, int j, int N, int M)
{
    return (i >= 0 && i < N && j >= 0 && j < M);
}

void bfs(vector<vector<char>> &mat, vector<vector<bool>> &vis, int Si, int Sj)
{
    int N = mat.size();
    int M = mat[0].size();

    queue<pair<int, int>> q;
    q.push({Si, Sj});
    vis[Si][Sj] = true;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        int i = current.first;
        int j = current.second;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (validate(ni, nj, N, M) && mat[ni][nj] == '.' && !vis[ni][nj])
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    vector<vector<char>> mat(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mat[i][j];
        }
    }

    int Si, Sj, Di, Dj;
    cin >> Si >> Sj >> Di >> Dj;

    vector<vector<bool>> vis(N, vector<bool>(M, false));
    bfs(mat, vis, Si, Sj);

    if (vis[Di][Dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}