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
 
const int N = 2e5; 
struct query{
    int l, r, id, block, ans;
    bool operator< (query P) const {
        return (make_pair(block, r) < make_pair(P.block, P.r));
    }
} q[N];
int a[N];
void solve() {
    int n;
    cin >> n;
    int m = sqrt(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int qr;
    cin >> qr;
    for(int i = 0; i < qr; ++i){
        cin >> q[i].l >> q[i].r;
        --q[i].l;
        --q[i].r;
        q[i].id = i;
        q[i].block = q[i].l / m;
    }
    sort(q, q + qr);
    unordered_map<int, int> freq;
    int distinct = 0;
    auto add = [&](int x){
        distinct += (freq[x] == 0);
        ++freq[x];
    };
    auto remove = [&](int x){
        --freq[x];
        distinct -= (freq[x] == 0);
    };
    int x = 0, y = 0;
    for(int i = 0; i < qr; ++i){
        // adding y
        while(y <= q[i].r){
            add(a[y]);
            ++y;
        }
        // removing y
        while(y > q[i].r + 1){
            --y;
            remove(a[y]);
        }
        // removing x
        while(x < q[i].l){
            remove(a[x]);
            ++x;
        }
        // adding x
        while(x > q[i].l){
            --x;
            add(a[x]);
        }
        q[i].ans = distinct;
    }
    sort(q, q + qr,
            [](query q1, query q2){
            return (q1.id < q2.id);
            }
            );
    for(int i = 0; i < qr; ++i){
        cout << (q[i].ans) << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
