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
 
 
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> d(n);
    int cur = a[0];
    int sz = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == cur){
            ++sz;
        }
        else{
            d[i - 1] = sz;
            sz = 1;
            cur = a[i];
        }
    }
    d[n - 1] = sz;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> prev(n, -1), next(n, -1);
    int p = -1;

    for(int i = 0; i < n; ++i){
        if(d[i] > 0){
            pq.push({d[i], i});

            prev[i] = p;
            if(p != -1){
                next[p] = i;
            }
            p = i;
        }
    }
    int cnt = 0;

    while(!pq.empty()){
        int dd, i;
        tie(dd, i) = pq.top();
        pq.pop();

        if(dd < d[i]){
            continue;
        }

        cnt = max(cnt, d[i]);

        int pr = prev[i];
        int nx = next[i];

        if(pr != -1){
            next[pr] = nx;
        }
        if(nx != -1){
            prev[nx] = pr;
        }

        if((pr != -1) && (nx != -1) && (a[pr] == a[nx])){
            int ppr = prev[pr];
            prev[nx] = ppr;
            if(ppr != -1){
                next[ppr] = nx;
            }
            d[nx] += d[pr] - d[i];
            pq.push({d[nx], nx});
        }
    }

    if(cnt & 1){
        cout << "Alice\n";
    }
    else{
        cout << "Bob\n";
    }
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
 
