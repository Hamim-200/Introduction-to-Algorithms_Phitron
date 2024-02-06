#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n, e;
    cin >> n >> e;

    ll adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = LLONG_MAX;
            if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1][b - 1] = min(adj[a - 1][b - 1], (ll)c);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] != LLONG_MAX && adj[k][j] != LLONG_MAX && adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll src, des;
        cin >> src >> des;
        if (adj[src - 1][des - 1] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj[src - 1][des - 1] << endl;
        }
    }

    return 0;
}
