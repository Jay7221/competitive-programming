#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<pair<int, int>> queries;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries.push_back({l, r});
    }
    vector<ll> pre(n + 1);
    for(auto [l, r] : queries){
        ++pre[l];
        --pre[r + 1];
    }
    for(int i = 1; i < n; ++i){
        pre[i] += pre[i - 1];
    }
    pre.pop_back();
    ll ans = 0;
    priority_queue<pair<ll, int>> pq;
    for(int i = 0; i < n; ++i){
        pq.push({pre[i], i});
    }
    vector<int> v(n);

    for(int elem : a){
        ll x, ind;
        tie(x, ind) = pq.top();
        pq.pop();
        v[ind] = elem;
        ans += elem * x;
    }

    cout << ans << '\n';
    for(int elem : v){
        cout << elem << ' ';
    }
    cout << '\n';
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
