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
 
const ll INF = 1e18 + 7;

ll getValue(ll ind, vector<ll> &index, vector<ll> &value){
    int i = upper_bound(index.begin(), index.end(), ind) - index.begin() - 1;
    if(ind % index[i] == 0){
        return value[i];
    }
    return getValue(ind % index[i], index, value);
}
 
void solve() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> operations(n);
    for(int i = 0; i < n; ++i){
        int type, x;
        cin >> type >> x;
        operations[i] = {type, x};
    }

    vector<ll> index;
    vector<ll> value;
    ll len = 0;
    for(auto [type, x]: operations){
        if(type == 1){
            ++len;
            index.push_back(len);
            value.push_back(x);
        }
        else{
            ++x;
            if((INF + x - 1) / x <= len){
                break;
            }
            len *= x;
        }
    }

    index.push_back(INF);
    value.push_back(-1);

    while(q--){
        ll i;
        cin >> i;
        cout << getValue(i, index, value) << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
