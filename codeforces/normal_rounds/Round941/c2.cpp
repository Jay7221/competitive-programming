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

string process(string s){
    string s_processed;
    ll cnt = 0;
    char prev = '$';
    for(char ch: s){
        if(ch != prev){
            if(cnt > 0){
                if(cnt & 1){
                    s_processed.push_back(prev);
                }
                else{
                    s_processed.push_back(prev);
                    s_processed.push_back(prev);
                }
            }
            cnt = 0;
            prev = ch;
        }
        ++cnt;
    }
    if(cnt & 1){
                s_processed.push_back(prev);
    }
    else{
                s_processed.push_back(prev);
                s_processed.push_back(prev);
    }
    return s_processed;
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

bool isPrime(ll n){
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
 
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    s = process(s);
    n = s.size();

    HashString h(s, 1e9 + 7), h1(s, 1e9 + 207);

    auto check = [&](ll l, ll r){
        if((l & 1) == (r & 1)){
            return false;
        }
        ll m = (l + r) / 2;
        if(h.get_hash(l, m) != h.get_rev_hash(m + 1, r)){
            return false;
        }
        if(h1.get_hash(l, m) != h1.get_rev_hash(m + 1, r)){
            return false;
        }
        return true;
    };

    ll l = 0;
    for(ll i = 1; i < n; ++i){
        if((l & 1) != (i & 1)){
            if(check(l, i)){
                ll m = (l + i) / 2;
                l = m + 1;
            }
        }
    }
    ll r = n - 1;
    for(ll i = n - 2; i >= l; --i){
        if(check(i, r)){
            ll m = (i + r) / 2;
            if(h.get_hash(i, m) == h.get_rev_hash(m + 1, r)){
                r = m;
            }
        }
    }
    ll len = r - l + 1;
    cout << len << '\n';
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
 
