#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++)
        make_set(i);

    long long int total_cost = 0;
    int edge_count = 0;

    for (auto edge : edges)
    {
        int a = edge.second.first;
        int b = edge.second.second;
        int c = edge.first;

        if (find_set(a) != find_set(b))
        {
            total_cost += c;
            union_sets(a, b);
            edge_count++;
        }

        if (edge_count == n - 1)
            break;
    }

    if (edge_count == n - 1)
        cout << total_cost << endl;
    else
        cout << -1 << endl;

    return 0;
}
