#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 1005;
int dp[MAX_NUM][MAX_NUM];

bool subsetSum(int n, const vector<int> &marks, int target)
{
    if (target == 0)
        return true;
    if (n == 0)
        return false;
    if (dp[n][target] != -1)
        return dp[n][target];
    if (marks[n - 1] <= target)
        return dp[n][target] = subsetSum(n - 1, marks, target - marks[n - 1]) || subsetSum(n - 1, marks, target);
    return dp[n][target] = subsetSum(n - 1, marks, target);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, M;
        cin >> n >> M;
        vector<int> marks(n);
        for (int i = 0; i < n; i++)
        {
            cin >> marks[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= 1000; j++)
            {
                dp[i][j] = -1;
            }
        }
        int target = 1000 - M;
        if (subsetSum(n, marks, target))
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