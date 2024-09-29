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

const ll MAX = 1e12 + 7;

bool checkMax(vector<ll> &a, ll mx){
    ll cursum = 0;
    for(ll elem: a){
        if(elem < mx){
            cursum -= min(cursum, mx - elem);
        }
        else if(elem > mx){
            cursum += elem - mx;
        }
    }
    return (cursum == 0ll);
}

ll getMinMax(vector<ll> &a){
    ll l = 1, r = MAX;

    while(l < r){
        ll mid = (l + r) / 2;
        if(checkMax(a, mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}

bool checkMin(vector<ll> &a, ll mn){
    ll cursum = 0;
    for(ll elem: a){
        if(elem > mn){
            cursum += elem - mn;
        }
        else{
            cursum -= mn - elem;
            if(cursum < 0){
                return false;
            }
        }
    }
    return true;
}

ll getMaxMin(vector<ll> &a, ll mx){
    ll l = 1, r = mx;

    while(l < r){
        ll mid = (l + r + 1) / 2;
        if(checkMin(a, mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }

    return l;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    ll mx = getMinMax(a);
    ll mn = getMaxMin(a, mx);
    cout << mx - mn << '\n';
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
 
