#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

void solve(){
    ll n, m;
    cin >> n >> m;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for(ll i = 0; i < m; ++i){
        ll d, v;
        cin >> d >> v;
        pq.push({d, v});
    }
    priority_queue<ll> coins;
    ll ans = 0;
    for(int day = 1; day <= n; ++day){
        while(!pq.empty() && (pq.top().first <= day)){
            coins.push(pq.top().second);
            pq.pop();
        }
        if(!coins.empty()){
            ans += (n - day + 1) * coins.top();
            coins.pop();
        }
    }
    cout << ans << '\n';
}
int main(){
    solve();
    return 0;
}
