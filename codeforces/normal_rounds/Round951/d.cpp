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
    int n, k;
    cin >> n >> k;
    string tmp;
    cin >> tmp;
    vector<bool> a(n);
    for(int i = 0; i < n; ++i){
        a[i] = tmp[i] - '0';
    }

    vector<bool> pre(n, true);
    bool cur = a[0];
    for(int i = 1; i < n; ++i){
        if(i % k == 0){
            cur ^= 1;
        }
        pre[i] = pre[i - 1] && (a[i] == cur);
    }

    vector<int> sum(n);
    for(int i = 0; i < n; ++i){
        sum[i] = a[i];
        if(i > 0){
            sum[i] += sum[i - 1];
        }
    }

    auto get_sum = [&](int l, int r){
        int ans = sum[r];
        if(l > 0){
            ans -= sum[l - 1];
        }
        return ans;
    };

    vector<bool> suf(n + 1, false);
    suf[n] = suf[n - 1] = true;

    for(int l = n - 2; l >= 0; --l){
        int r = min(n - 1, l + k - 1);
        if(a[l]){
            if(get_sum(l, r) == (r - l + 1)){
                suf[l] = suf[r + 1];
                if(r + 1 < n){
                    suf[l] = suf[l] && (a[l] != a[r + 1]);
                }
            }
        }
        else{
            if(get_sum(l, r) == 0){
                suf[l] = suf[r + 1];
                if(r + 1 < n){
                    suf[l] = suf[l] && (a[l] != a[r + 1]);
                }
            }
        }
    }

    for(int p = 0; p < n; ++p){
        if(suf[p + 1] && pre[p]){
            if(p % k == k - 1){
                if(a[p] != a[n - 1]){
                    cout << p + 1 << '\n';
                    return;
                }
            }
            else{
                if(a[p] == a[n - 1]){
                    cout << p + 1 << '\n';
                    return;
                }
            }
        }
    }

    cout << -1 << '\n';
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
 
