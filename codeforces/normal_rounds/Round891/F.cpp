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
 
 
ll sqrt(ll n){
    if(n < 0){
        return -1;
    }
    if(n == 0){
        return 0;
    }
    ll l = 1, r = 2e9 + 7;
    while(l <= r){
        ll mid = (l + r) / 2;
        ll sq = mid * mid;
        if(sq == n){
            return mid;
        }
        else if(sq < n){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}
void solve() {
    int n;
    cin >> n;
    map<ll, ll> freq;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        ++freq[a];
    }
    int q;
    cin >> q;
    vector<ll> ans;
    while(q--){
        ll x, y;
        cin >> x >> y;
        ll det = sqrt(x * x - 4 * y);
        if(det == 0){
            ll t = x / 2;
            ans.push_back((freq[t] * (freq[t] - 1)) / 2);
        }
        else if(det == -1){
            ans.push_back(0);
        }
        else{
            ll t1 = (x - det) / 2, t2 = (x + det) / 2;
            if((t1 + t2 != x) || (t1 * t2 != y)){
                ans.push_back(0);
            }
            else{
                ans.push_back(freq[t1] * freq[t2]);
            }
        }
    }
    for(auto elem : ans){
        cout << elem << ' ';
    }
    cout << '\n';
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
 
