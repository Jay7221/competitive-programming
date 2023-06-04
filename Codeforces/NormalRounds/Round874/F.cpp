#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
const int MAX = 2e5 + 7;
vector<ll> fact(MAX);
ll add(ll a, ll b){
    return ((a + b) % MOD);
}
ll sub(ll a, ll b){
    return (((a - b) % MOD + MOD) % MOD);
}
ll mult(ll a, ll b){
    return ((a * b) % MOD);
}
ll power(ll a, ll p){
    ll ans = 1, rem = a;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, rem);
        }
        rem = mult(rem, rem);
        p >>= 1;
    }
    return ans;
}
ll inv(ll a){
    return power(a, MOD - 2);
}
ll divide(ll a, ll b){
    return mult(a, inv(b));
}
ll com(ll a, ll b){
    if(a < b){
        return 0ll;
    }
    return divide(fact[a], mult(fact[b], fact[a - b]));
}
void pre(){
    fact[0] = 1;
    for(int i = 1; i < MAX; ++i){
        fact[i] = mult(i, fact[i - 1]);
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    set<int> st;
    map<int, int> freq;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        ++freq[x];
        st.insert(x);
    }
    vector<int> v;
    for(int x : st){
    	v.push_back(x);
    }
    n = v.size();
    vector<int> pre(n);
    for(int i = 0; i < n; ++i){
    	pre[i] = freq[v[i]];
    }
    for(int i = 1; i < n; ++i){
    	pre[i] = mult(pre[i], pre[i - 1]);
    }
    ll ans = 0;
    for(int i = 0; i < v.size(); ++i){
    	int l = lower_bound(v.begin(), v.end(), v[i] - m + 1) - v.begin();
    	++l;
    	int r = i;
    	ans = add(ans, com(num - 1, m - 1));
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    pre();
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
