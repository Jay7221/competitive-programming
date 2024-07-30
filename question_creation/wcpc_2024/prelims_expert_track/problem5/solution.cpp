#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int mod = 1e9+7;

int main()
{
    fast;
    ll m, n;
    cin >> m >> n;

    vector<vector<ll>> p(m, vector<ll>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin>>p[i][j];
        }
    }

    auto possible = [&] (ll mid) -> bool {
        vector<ll> cnt(m), vis(n);
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                if(p[i][j] >= mid) {
                    cnt[i]++;
                    vis[j] = 1;
                }
            }
            if(vis[j] == 0) return false;
        }

        return *max_element(cnt.begin(), cnt.end()) > 1;
    };

    ll low = 1, high = 1e9;
    while(low <= high) {
        ll mid = low + (high - low) / 2;

        if(possible(mid)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low - 1 << endl;
    return 0;
}
