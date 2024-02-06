#include <bits/stdc++.h>
#define N 10001
using namespace std;

const long long ll = 1e18;
vector<pair<int, long long int>> adj[N];
long long int dis[N];

class cmp
{
public:
    bool operator()(pair<int, long long int> a, pair<int, long long int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int, long long int>, vector<pair<int, long long int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, long long int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        long long int cost = parent.second;

        for (pair<int, long long int> child : adj[node])
        {
            int childNode = child.first;
            long long int childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int src;
    cin >> src;
    for (int i = 0; i <= n; i++)
    {
        dis[i] = ll;
    }
    dijkstra(src);

    int t;
    cin >> t;
    while (t--)
    {
        int dest, maxCost;
        cin >> dest >> maxCost;

        if (dis[dest] <= maxCost && dis[dest] != ll)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}