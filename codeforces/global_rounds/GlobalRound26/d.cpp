#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
ll add(ll a, ll b, ll mod){
    a = ((a % mod) + mod) % mod;
    b = ((b % mod) + mod) % mod;
    return ((a + b) % mod);
}
ll sub(ll a, ll b, ll mod){
    a = ((a % mod) + mod) % mod;
    b = ((b % mod) + mod) % mod;
    return (((a - b) % mod + mod) % mod);
}
ll mult(ll a, ll b, ll mod){
    a = ((a % mod) + mod) % mod;
    b = ((b % mod) + mod) % mod;
    return ((a * b) % mod);
}
ll power(ll a, ll p, ll mod){
    a = ((a % mod) + mod) % mod;
    ll ans = 1;
    while(p > 0){
        if(p & 1){
            ans = mult(ans, a, mod);
        }
        a = mult(a, a, mod);
        p >>= 1;
    }
    return ans;
}
ll divide(ll a, ll b, ll mod){
    return mult(a, power(b, mod - 2, mod),mod);
}

class HashString{
    ll n;
    vector<ll> pre, suf;
    ll mod;
public:
    HashString(string s, ll mod){
        this -> mod = mod;
        n = s.size();
        pre.resize(n);
        suf.resize(n);
        for(ll i = 0; i < n; ++i){
            pre[i] = (s[i] - '0');
            suf[i] = (s[i] - '0');
        }
        for(ll i = 1; i < n; ++i){
            pre[i] = add(pre[i - 1], mult(pre[i], power(2, i, mod), mod), mod);
        }
        for(ll i = n - 2; i >= 0; --i){
            suf[i] = add(suf[i + 1], mult(suf[i], power(2, n - 1 - i, mod), mod), mod);
        }
    }
    ll get_hash(ll l, ll r){
        --l;
        ll ans = pre[r];
        if(l >= 0){
            ans = sub(ans, pre[l], mod);
            ans = divide(ans, power(2, l + 1, mod), mod);
        }
        return ans;
    }
    ll get_rev_hash(ll l, ll r){
        ++r;
        ll ans = suf[l];
        if(r < n){
            ans = sub(ans, suf[r], mod);
            ans = divide(ans, power(2, n - r, mod), mod);
        }
        return ans;
    }
};

 
void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> ind;
    for(ll i = 0; i < n; ++i){
        if(s[i] != 'a'){
            ind.push_back(i);
        }
    }
    if(ind.empty()){
        cout << n - 1 << '\n';
        return;
    }
    ll m = ind.size();

    ll MOD1 = 1e9 + 7;
    ll MOD2 = 1e9 + 9;
    HashString hash1(s, MOD1);
    HashString hash2(s, MOD2);

    auto equals = [&](ll l1, ll r1, ll l2, ll r2){
        if((r1 - l1) != (r2 - l2)){
            return false;
        }
        return (
                (hash1.get_hash(l1, r1) == hash1.get_hash(l2, r2))
                && 
                (hash2.get_hash(l1, r1) == hash2.get_hash(l2, r2))
                 );
    };

    auto check = [&](ll d){
        for(ll i = d; i < m; i += d){
            if(!equals(ind[0], ind[d - 1], ind[i], ind[i + d - 1])){
                return false;
            }
        }
        return true;
    };

    auto get = [&](ll d){
        ll n1 = ind[0];
        ll n2 = n - 1 - ind.back();
        ll sm = n1 + n2;
        for(ll i = d; i < m; i += d){
            sm = min(sm, ind[i] - ind[i - 1] - 1);
        }
        ll ans = 0;
        for(ll i = 0; i <= min(n1, sm); ++i){
            ans += 1 + min(sm - i, n2);
        }
        return ans;
    };


    ll ans = 0;
    for(ll d = 1; d <= m; ++d){
        if(m % d == 0){
            if(check(d)){
                ans += get(d);
                cerr << d << " : " << get(d) << '\n';
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
