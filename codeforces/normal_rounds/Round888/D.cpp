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
    ll n;
    cin >> n;
    vector<ll> a(n - 1);
    for(ll &elem : a){
        cin >> elem;
    }
    for(int i = a.size() - 1; i > 0; --i){
        a[i] -= a[i - 1];
    }

    set<ll> missing;
    map<ll, int> freq;
    for(int i = 1; i <= n; ++i){
        missing.insert(i);
    }
    for(ll &elem : a){
        ++freq[elem];
        missing.erase(elem);
    }
    bool flag = false;
    if(missing.size() == 1){
        flag = true;
    }
    else if(missing.size() == 2){
        ll x, y;
        x = *missing.begin();
        missing.erase(missing.begin());
        y = *missing.begin();
        for(ll elem : a){
            if((x + y == elem) && ((freq[elem] > 1) || (elem > n))){
                flag = true;
            }
        }
    }
    if(flag){
        cout << "YES\n";
    }else{
        cout << "NO\n";
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
 
