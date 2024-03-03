#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    parent[node] = dsu_find(parent[node]);
    return parent[node];
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (group_size[leaderA] > group_size[leaderB])
        {
            parent[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end(), cmp);

    dsu_initialize(n);

    int totalCost = 0;
    int edgeCount = 0;

    for (Edge edge : edges)
    {
        int leaderU = dsu_find(edge.u);
        int leaderV = dsu_find(edge.v);
        if (leaderU != leaderV)
        {
            dsu_union(leaderU, leaderV);
            totalCost += edge.w;
            edgeCount++;
        }
        if (edgeCount == n - 1)
            break; 
    }

    int roadsToRemove = m - edgeCount;
    if (edgeCount == n - 1)
    {
        cout << roadsToRemove << " " << totalCost << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }

    return 0;
}
