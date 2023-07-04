#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>
void debug(T arr){
    for(int elem : arr){
        cerr << elem << ' ';
    }
    cerr << '\n';
}
void solve(){
    ll n, k, A;
    cin >> n >> k >> A;
    vector<tuple<ll, ll, ll>> a(n);
    vector<ll> x(n), y(n), c(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i] >> c[i];
        a[i] = {x[i], y[i], c[i]};
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i){
        tie(x[i], y[i], c[i]) = a[i];
    }
    vector<ll> pre = c;
    for(int i = 1; i < n; ++i){
        pre[i] += pre[i - 1];
    }

    auto cost = [&](ll x, ll y){
        return A * (k - (x + y));
    };

    vector<ll> dp = pre;

    dp[0] = min(dp[0], cost(x[0], y[0]));
    ll delta = dp[0] - pre[0];

    multiset<ll> m;
    stack<pair<ll, ll>> st;
    st.push({y[0], cost(x[0], y[0])});
    m.insert(cost(x[0], y[0]));


    for(int i = 1; i < n; ++i){
        dp[i] = min(dp[i], pre[i] + delta);

        ll val = dp[i - 1] + cost(x[i], y[i]);
        while(st.size() > 0 && st.top().first >= y[i]){
            ll y2, val2;
            tie(y2, val2) = st.top();
            st.pop();
            m.erase(m.find(val2));
            val2 += A * (y2 - y[i]);
            val = min(val, val2);
        }
        st.push({y[i], val});
        m.insert(val);
        cerr << *m.begin() << '\n';

        dp[i] = min(dp[i], *m.begin());

        delta = min(delta, dp[i] - pre[i]);
    }
    debug(dp);
    cout << dp[n - 1] << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
