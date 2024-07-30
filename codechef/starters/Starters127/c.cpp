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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    auto check = [&](ll x){
        ll cnt = 0;
        ll cntk = 0;
        ll cnt2 = 0;
        priority_queue<ll> pq;
        for(ll elem: a){
            if(elem >= x){
                ++cnt;
                if(elem % k){
                    continue;
                }
                while((elem % k == 0) && ((elem / k) >= x)){
                    elem /= k;
                    ++cntk;
                }
                ll tmp = 0;
                while(elem % k == 0){
                    ++tmp;
                    elem /= k;
                }
                if(tmp > 0){
                    pq.push(tmp);
                }
            }
            else{
                if(elem % k == 0){
                    while(elem % k == 0){
                        ++cntk;
                        elem /= k;
                    }
                }
                else{
                    cnt2 += (elem * k >= x);
                }
            }
        }
        ll tmp = min(cnt2, cntk);
        cnt += tmp;
        cnt2 -= tmp;

        while(!pq.empty() && (cnt2 > 0)){
            ll tmp = min(cnt2, pq.top());
            cnt += tmp - 1;
            cnt2 -= tmp;
            pq.pop();
        }

        return (cnt >= x);
    };

    int l = 1, r = n;
    while(l < r){
        int m = (l + r + 1) >> 1;
        if(check(m)){
            l = m;
        }
        else{
            r = m - 1;
        }
    }
    cout << l << '\n';
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
 
