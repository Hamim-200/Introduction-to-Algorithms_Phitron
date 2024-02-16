#include <bits/stdc++.h>
using namespace std;

int parent[100];
int level[100];
int groupSize[100];

void initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        level[i] = 0;
        groupSize[i] = 1;
    }
}

int find(int n)
{
    while (parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}

// Naive Approch
void dsu_union(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);
    if (leaderA != leaderB)
    {
        parent[leaderB] = leaderA;
    }
}

void dsu_union_by_rank(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);
    if (leaderA != leaderB)
    {
        if (level[leaderA] > level[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (level[leaderB] > level[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else{
            parent[leaderA] = leaderB;
            level[leaderB] ++;
        }
    }
}

void dsu_union_by_group(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);
    if (leaderA != leaderB)
    {
        if (groupSize[leaderA] > groupSize[leaderB])
        {
            parent[leaderB] = leaderA;
            groupSize[leaderA] += groupSize[leaderB];
        }
        else{
            parent[leaderA] = leaderB;
            groupSize[leaderB] += groupSize[leaderA];
        }
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    initialize(node);
    while (edge--)
    {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v);
    }
    for (int i = 1; i <= node; i++)
    {
        cout << parent[i] << " ";
    }

    return 0;
}