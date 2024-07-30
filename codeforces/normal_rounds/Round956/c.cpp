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
 
bool check(vector<ll> &a, int l, int r, ll req){
    ll sum = 0;
    if(l > r){
        return false;
    }
    for(int i = l; i <= r; ++i){
        sum += a[i];
    }
    return (sum >= req);
}

int get(vector<ll> &a, ll req, int l){
    ll sum = 0;
    for(int i = l; i < (int)a.size(); ++i){
        sum += a[i];
        if(sum >= req){
            return i;
        }
    }
    return (int)a.size() - 1;
}

bool check(vector<ll> &a, vector<ll> &b, vector<ll> &c, ll req){
    int la = 1;
    int ra = get(a, req, la);

    int lb = ra + 1;
    int rb = get(b, req, lb);

    int lc = rb + 1;
    int rc = get(c, req, lc);

    return (check(a, la, ra, req) && check(b, lb, rb, req) && check(c, lc, rc, req));
}
vector<pair<int, int>> get(vector<ll> &a, vector<ll> &b, vector<ll> &c, ll req){
    int la = 1;
    int ra = get(a, req, la);

    int lb = ra + 1;
    int rb = get(b, req, lb);

    int lc = rb + 1;
    int rc = get(c, req, lc);

    return (vector<pair<int, int>>){{la, ra}, {lb, rb}, {lc, rc}};
}
 
void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    ll tot = accumulate(a.begin(), a.end(), 0ll);
    ll req = (tot + 2) / 3;

    int la, ra, lb, rb, lc, rc;
    vector<pair<int, int>> res;
    if(check(a, b, c, req)){
        res = get(a, b, c, req);
    }
    else if(check(a, c, b, req)){
        res = get(a, c, b, req);
        swap(res[1], res[2]);
    }
    else if(check(b, a, c, req)){
        res = get(b, a, c, req);
        swap(res[0], res[1]);
    }
    else if(check(b, c, a, req)){
        res = get(b, c, a, req);
        swap(res[1], res[2]);
        swap(res[0], res[1]);
    }
    else if(check(c, a, b, req)){
        res = get(c, a, b, req);
        swap(res[0], res[1]);
        swap(res[1], res[2]);
    }
    else if(check(c, b, a, req)){
        res = get(c, b, a, req);
        swap(res[0], res[2]);
    }
    else{
        cout << -1 << '\n';
        return;
    }

    tie(la, ra) = res[0];
    tie(lb, rb) = res[1];
    tie(lc, rc) = res[2];
    cout << la << ' ' << ra << ' ' << lb << ' ' << rb << ' ' << lc << ' ' << rc << '\n';
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
 
