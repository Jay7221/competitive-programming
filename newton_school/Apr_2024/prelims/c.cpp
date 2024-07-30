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
 
int get(char ch){
    if(('a' <= ch) && (ch <= 'z')){
        return (ch - 'a');
    }
    return (26 + (ch - 'A'));
}
char get(int ch){
    if(ch < 26){
        return ('a' + ch);
    }
    return ('A' + (ch - 26));
}
const int LOGMAX = 52;
 
const ll INF = 1e18 + 7;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> freq(n, vector<int>(LOGMAX));
    vector<bool> vis(LOGMAX);
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(char ch: s){
            ++freq[i][get(ch)];
            vis[get(ch)] = true;
        }
    }


    auto calc = [&](int delch){
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                ll tmp = 0;
                for(int c = 0; c < LOGMAX; ++c){
                    if(c == delch){
                        continue;
                    }
                    tmp += min(freq[i][c], freq[j][c]);
                }
                ans += 1 + tmp * tmp;
            }
        }
        ans <<= 1;
        return ans;
    };

    ll ans = INF;
    char ch = '#';
    for(int c = 0; c < LOGMAX; ++c){
        if(calc(c) < ans){
            ans = calc(c);
            ch = get(c);
        }
    }
    cout << ans << ' ' << ch << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
