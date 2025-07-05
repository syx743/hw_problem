#include <iostream>
#include <vector>
using namespace std;
using PII = pair<int, int>;
#define x first
#define y second

void solve()
{
    int m, n, x;
    cin >> m >> n >> x;
    vector<PII> a(x);
    for (int i = 0; i < x; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    int ans = 0;
    for (int i = 0; i < (1 << x); i++)
    {
        vector<int> cnt(n, 0);
        bool ok = true;
        int res = 0;
        for (int j = 0; ok && j < x; j++)
        {
            if (i >> j & 1)
            {
                for (int k = a[j].x; ok && k < a[j].y; k++)
                {
                    ++cnt[k];
                }
                res += a[j].y - a[j].x;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (cnt[j] > m)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            ans = max(ans, res);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    system("pause");
    return 0;
}
