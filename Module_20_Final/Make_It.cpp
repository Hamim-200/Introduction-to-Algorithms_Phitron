#include <bits/stdc++.h>
using namespace std;

bool make_it(int num)
{
    vector<bool> dp(num + 1, false);

    dp[0] = true;

    for (int i = 0; i <= num; i++)
    {
        if (dp[i])
        {
            if (i + 3 <= num)
                dp[i + 3] = true;
            if (i * 2 <= num)
                dp[i * 2] = true;
        }
    }

    return dp[num];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (make_it(n))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}