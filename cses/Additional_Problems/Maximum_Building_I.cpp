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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }
    vector<vector<int>> h(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            h[i][j] = (grid[i][j] == '.');
        }
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(h[i][j] > 0){
                h[i][j] += h[i - 1][j];
            }
        }
    }
    ll ans = 0;
    for(int row = 0; row < n; ++row){
        // left[i] = first index from left k, such that h[row][k] < h[row][i]
        vector<int> left(m), right(m);
        for(int col = 0; col < m; ++col){
            left[col] = -1;
            right[col] = m;
        }
        stack<int> st;
        for(int col = 0; col < m; ++col){
            while(!st.empty()){
                int ind = st.top();
                if(h[row][ind] < h[row][col]){
                    break;
                }
                st.pop();
            }
            if(!st.empty()){
                left[col] = st.top();
            }
            st.push(col);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int col = m - 1; col >= 0; --col){
            while(!st.empty()){
                int ind = st.top();
                if(h[row][ind] < h[row][col]){
                    break;
                }
                st.pop();
            }
            if(!st.empty()){
                right[col] = st.top();
            }
            st.push(col);
        }
        for(int col = 0; col < m; ++col){
            ll area = h[row][col] * 1ll * (right[col] - left[col] - 1);
            ans = max(ans, area);
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    tc = 1;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
