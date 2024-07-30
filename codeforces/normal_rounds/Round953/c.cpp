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
 
ll get(vector<int> p){
    int n = p.size();
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ans += abs(p[i] - (i + 1));
    }
    return ans;
}
 
void solve() {
    ll n, k;
    cin >> n >> k;
    ll mx;
    if(n & 1){
        mx = n / 2;
        mx = 2 * mx * (mx + 1);
    }
    else{
        mx = n / 2;
        mx = 2 * mx * mx;
    }
    cerr << n << ' ' << mx << '\n';
    if((k & 1) || (k > mx)){
        cout << "No\n";
        return;
    }

    ll rem = k;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        p[i] = i + 1;
    }

    ll r = n - 1;
    for(ll i = 0; i < n; ++i){
        ll j = min(r, i + rem / 2);
        j = max(j, i);
        r = j - 1;
        rem -= 2 * (j - i);
        swap(p[i], p[j]);
    }

    cout << "Yes\n";
    for(int elem: p){
        cout << elem << ' ';
    }
    cout << '\n';
    assert(get(p) == k);
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
 
