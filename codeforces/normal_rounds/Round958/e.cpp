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
    vector<int> a(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vector<int> l(n + 2), r(n + 2);
    stack<int> st;
    st.push(0);
    for(int i = 1; i <= n; ++i){
        while(a[i] < a[st.top()]){
            st.pop();
        }
        l[i] = st.top();
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    st.push(n + 1);
    for(int i = n; i > 0; --i){
        while(a[i] <= a[st.top()]){
            st.pop();
        }
        r[i] = st.top();
        st.push(i);
    }

    vector<int> pre(n + 2);
    vector<int> suf(n + 2);
    vector<vector<int>> L(n + 2), R(n + 2);
    for(int i = 1; i <= n; ++i){
        L[l[i]].push_back(i);
        R[r[i]].push_back(i);

        pre[l[i] + 1] += a[i];
        pre[r[i]] -= a[i];

        suf[l[i]] -= a[i];
        suf[r[i] - 1] += a[i];

    }
    cerr << pre << '\n';
    for(int i = 1; i <= n; ++i){
        pre[i] += pre[i - 1];
    }
    cerr << pre << '\n';
    for(int i = 1; i <= n; ++i){
        pre[i] += pre[i - 1];
    }
    cerr << pre << '\n';
    for(int i = n - 1; i >= 1; --i){
        suf[i] += suf[i + 1];
    }
    for(int i = n - 1; i >= 1; --i){
        suf[i] += suf[i + 1];
    }


    ll tot = 0;
    for(int i = 1; i <= n; ++i){
        tot += a[i] * (r[i] - l[i] - 1);
    }
    cerr << tot << '\n';

    vector<ll> res(n + 2);
    for(int i = 1; i <= n; ++i){
        res[i] = tot;
        res[i] -= pre[i] + suf[i];
        for(int j: L[i]){
            res[i] += a[j] * (i - l[i]);
        }
        for(int j: R[i]){
            res[i] += a[j] * (r[i] - i);
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
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
 
