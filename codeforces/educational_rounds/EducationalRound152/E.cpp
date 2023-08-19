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
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        --p[i];
    }
    // stmn = [{ value, index }]
    // stmx = [{ value, index }]
    vector<pair<int, int>> stmn, stmx;
    stmn.push_back({-1, -1});
    stmx.push_back({n, -1});
    ll ans = 0;
    int len = 0;
    // cur = [{ index, type }]
    set<pair<int, int>> cur;
    cur.insert({-1, 0});
    cur.insert({-1, 1});
    for(int i = 0; i < n; ++i){
        while(stmn.back().first > p[i]){
            auto me = cur.lower_bound({stmn.back().second, 0});

            auto prev = me;
            --prev;
            auto next = me;
            ++next;

            len -= (me -> first - prev -> first);
            if((next != cur.end()) && (next -> second == 0)){
                len += next -> first - prev -> first;
            }

            stmn.pop_back();
            cur.erase(me);
        }
        len += i - cur.rbegin() -> first;
        cur.insert({i, 0});
        stmn.push_back({p[i], i});

        while(stmx.back().first < p[i]){
            auto me = cur.lower_bound({stmx.back().second, 1});

            auto prev = me;
            --prev;
            auto next = me;
            ++next;

            if((next != cur.end()) && (next -> second == 0)){
                len += (me -> first - prev -> first);
            }

            stmx.pop_back();
            cur.erase(me);
        }
        cur.insert({i, 1});
        stmx.push_back({p[i], i});

        ans += len;
    }
    ans -= n;
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
