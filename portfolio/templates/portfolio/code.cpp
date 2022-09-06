#include <bits/stdc++.h>
#define int long long int
#define IOS()                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
const int sz = 2 * 1e5 + 5;
using namespace std;
int power(int x, int y, int m)
{
    if (y == 0)
        return 1;

    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}
int mdinn(int n) { return power(n, mod - 2, mod); }
signed main()
{
    IOS();
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int black = 0, white = 0;
            for (int k = 0; k < m; k++)
            {
                if (a[i][k] == 0)
                    white++;
                if (a[i][k] == 1)
                    black++;
            }
            for (int k = 0; k < n; k++)
            {
                if (a[k][j] == 0)
                    white++;
                if (a[k][j] == 1)
                    black++;
            }
            ans = max(ans, black - white);
        }
    }
    cout << ans << "\n";
}