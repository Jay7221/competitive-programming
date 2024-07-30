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
vector < vector < int >> maximumInMatrices(int n, int m, int R, int S,
    vector < vector < int >> & a) {
    vector<vector<int>> ans(n, vector<int>(m));


    for(int i = 0; i < n; ++i){

        multiset<int> st;
        for(int l = m - 1, r = m - 1; l >= 0; --l){
            st.insert(a[i][l]);

            if(r - l + 1 > S){
                st.erase(st.find(a[i][r]));
                --r;
            }

            ans[i][l] = *(--st.end());
        }
    }
    a = ans;

    for(int j = 0; j < m; ++j){
        multiset<int> st;

        for(int l = n - 1, r = n - 1; l >= 0; --l){
            st.insert(a[l][j]);
            if(r - l + 1 > R){
                st.erase(st.find(a[r][j]));
                --r;
            }
            ans[l][j] = *(--st.end());
        }
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, r, s;
        cin >> n >> m >> r >> s;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> a[i][j];
            }
        }
        a = maximumInMatrices(n, m, r, s, a);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}
