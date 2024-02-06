#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const long long maxVal = 1e18;
const int N = 1e5 + 5;
long long dis[N];

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    for (int i = 1; i <= n; ++i)
    {
        dis[i] = maxVal;
    }

    int src;
    cin >> src;
    int t;
    cin >> t;

    dis[src] = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < maxVal && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < maxVal && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    for (int i = 0; i < t; ++i)
    {
        int dest;
        cin >> dest;
        if (dis[dest] != maxVal)
        {
            cout << dis[dest] << endl;
        }
        else
        {
            cout << "Not Possible" << endl;
        }
    }

    return 0;
}
