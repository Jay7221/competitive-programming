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
    vector<int> a(3 * n), b(3 * n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    vector<int> pre(3 * n);
    for(int i = 0; i < n; ++i){
        if(a[i] < b[i]){
            pre[i] = -1;
        }
        else if(a[i] == b[i]){
            pre[i] = 0;
        }
        else{
            pre[i] = 1;
        }
        pre[i + n] = -pre[i];
        pre[i + 2 * n] = pre[i];
        a[i + n] = b[i];
        b[i + n] = a[i];
        a[i + 2 * n] = a[i];
        b[i + 2 * n] = b[i];
    }
    for(int i = 1; i < 3 * n; ++i){
        pre[i] += pre[i - 1];
    }
    auto get = [&](int l, int r){
        int ans = pre[r];
        if(l > 0){
            ans -= pre[l - 1];
        }
        return ans;
    };
    auto check = [&](int l, int r){
        while(l <= r){
            if(a[l] != b[r]){
                return false;
            }
            ++l;
            --r;
        }
        return true;
    };
    int ans = -1;
    for(int k = 0; k < 2 * n; ++k){
        int l1, l2, r1, r2;
        l1 = 0 + k;
        r1 = l1 + n / 2 - 1;
        l2 = l1 + n / 2;
        if(n & 1){
            // n is odd
            ++l2;
        }
        r2 = l2 + n / 2 - 1;
        int s1 = get(l1, r1);
        int s2 = get(l2, r2);
        if((s1 == -(n / 2)) && (s2 == (n / 2))){
            if(check(l1, r2)){
                ans = k;
                break;
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}
 
