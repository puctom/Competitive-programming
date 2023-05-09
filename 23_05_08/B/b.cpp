#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 105;
int a[maxN][maxN];
int b[maxN * maxN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        if (n > m)
            swap(n, m);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> b[m * j + k];
            }
        }
        sort(b, b + m * n);
        // cout << "sorted: ";
        // for (int j = 0; j < m * n; j++)
        // {
        //     cout << b[j] << "  ";
        // }
        // cout << "\n ";
        long long res = 0;

        res += max((b[m * n - 1] - b[1]) * (n - 1), (b[m * n - 2] - b[0]) * (n - 1));

        res += ((b[m * n - 1] - b[0]) * ((m - 1) * n));
        cout << res << "\n";
        long long res2 = 0;
    }

    return 0;
}