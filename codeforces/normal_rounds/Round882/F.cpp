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
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 7;
const ld EPS = 1e-9;
 
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
 
const int LOGMAX = 30;
void solve() {
    int n, queries;
    cin >> n >> queries;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    vector<pair<ll, int>> v;
    // v[i] = {ind, val} => a[ind] = val
    for(int i = 0; i < n; ++i){
        v.push_back({i, arr[i]});
    }

    vector<int> val(n - 1);
    // val[i] = cur value of a[i + 1]
    queue<tuple<ll, int, int>> q;
    for(int i = 0; i < n - 1; ++i){
        val[i] = arr[i + 1];
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < LOGMAX; ++j){
            if((arr[i] >> j) & 1){
                q.push({ i + n, j, i % (n - 1) });
            }
        }
    }
    while(q.size() > 0){
        ll pos;
        int bit, ind;
        tie(pos, bit, ind) = q.front();
        q.pop();
        if((val[ind] >> bit) & 1){
            // val[ind] has bit set already
            continue;
        }
        val[ind] |= (1 << bit);
        v.push_back({ pos, val[ind] });
        q.push({ pos + n, bit, (ind + 1) % (n - 1) });
    }
    int m = v.size();
    vector<ll> index(m);
    vector<int> value(m);
    for(int i = 0; i < m; ++i){
        tie(index[i], value[i]) = v[i];
        ++index[i];
    }
    for(int i = 1; i < m; ++i){
        value[i] = max(value[i], value[i - 1]);
    }
    index.push_back(-1);

    while(queries--){
        int x;
        cin >> x;
        int l = 0, r = m;
        while(l < r){
            int mid = (l + r) / 2;
            if(value[mid] <= x){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        cout << index[l] << '\n';
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
 
