#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X;
        cin >> X;

        if (mat[X].empty())
        {
            cout << -1 << endl;
        }
        else
        {
            sort(mat[X].rbegin(), mat[X].rend());

            for (int i = 0; i < mat[X].size(); i++)
            {
                cout << mat[X][i];
                if (i != mat[X].size() - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
