#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 1e6 + 5;

int t, n, a[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for(int cases = 0; cases < t; cases++)
    {
        cin >> n;
        vector<pii> order;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            order.push_back({a[i], i});
        }
        sort(order.begin(), order.end());
        int ans = 0, cnt = 0, curways = 1;
        for(int i = 0; i < n; i++)
        {
            curways *= 2;
            curways %= MOD;
            if(i == n - 1 || order[i].second > order[i + 1].second)
            {
                ans += curways;
                ans %= MOD;
                cnt++;
                curways = 1;
            }
        }
        cout << (ans - (cnt - 1) + MOD) % MOD << "\n";
    }
    return 0;
}