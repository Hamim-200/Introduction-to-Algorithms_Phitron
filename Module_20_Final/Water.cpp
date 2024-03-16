#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int i = 0;
        int j = n - 1;
        int ans = INT_MIN, ai, aj;
        while (i < j)
        {
            if (min(arr[i], arr[j]) > ans)
            {
                ans = min(arr[i], arr[j]);
                ai = i;
                aj = j;
            }
            if (arr[i] < arr[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        cout << ai << " " << aj << endl;
    }
    return 0;
}