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
    vector<ll> a(n);
    int pos = 0, neg = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        pos += (a[i] > 0);
        neg += (a[i] < 0);
    }
    ll mx = *max_element(a.begin(), a.end());
    ll mn = *min_element(a.begin(), a.end());

    int mx_ind;
    for(int i = 0; i < n; ++i){
        if(a[i] == mx){
            mx_ind = i;
        }
    }
    int mn_ind;
    for(int i = 0; i < n; ++i){
        if(a[i] == mn){
            mn_ind = i;
        }
    }

    vector<pair<int, int>> query;
    auto add = [&](int i, int j){
        a[i] += a[j];
        query.push_back({i, j});
    };

    if(abs(mx) >= abs(mn)){
        if(neg <= 12){
            for(int i = 0; i < n; ++i){
                if(a[i] < 0){
                    add(i, mx_ind);
                }
            }
        }
        else{
            for(int i = 0; i < 5; ++i){
                add(mn_ind, mn_ind);
            }
            for(int i = 0; i < n; ++i){
                if(a[i] > 0){
                    add(i, mn_ind);
                }
            }
        }
    }
    else{
        if(pos <= 12){
            for(int i = 0; i < n; ++i){
                if(a[i] > 0){
                    add(i, mn_ind);
                }
            }
        }
        else{
            for(int i = 0; i < 5; ++i){
                add(mx_ind, mx_ind);
            }
            for(int i = 0; i < n; ++i){
                if(a[i] < 0){
                    add(i, mx_ind);
                }
            }
        }
    }

    if((*max_element(a.begin(), a.end())) > 0){
        for(int i = 1; i < n; ++i){
            add(i, i - 1);
        }
    }
    else{
        for(int i = n - 2; i >= 0; --i){
            add(i, i + 1);
        }
    }
    cout << query.size() << '\n';
    for(auto [u, v] : query){
        ++u, ++v;
        cout << u << ' ' << v << '\n';
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
 
