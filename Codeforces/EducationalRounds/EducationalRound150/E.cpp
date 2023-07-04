#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i){
        v[i] = {a[i], i + 1};
    }
    vector<ll> freq(n + 1);
    freq[n] = n;
    sort(v.rbegin(), v.rend());
    set<int> cols;
    cols.insert(0);
    cols.insert(n + 1);
    for(auto [ai, i] : v){
        int l = *(--cols.lower_bound(i));
        int r = *(cols.lower_bound(i));
        freq[r - l - 1] -= ai;
        freq[i - l - 1] += ai;
        freq[r - i - 1] += ai;
        cols.insert(i);
    }
    ll m;
    cin >> m;
    ll cur = m;
    ll ans = 0;
    for(int i = n; i >= 1; --i){
        ll k = min(freq[i], (cur + i - 1) / i);
        cur -= min(k * i, cur);
        ans += k;
    }
    ans = m - ans;
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
