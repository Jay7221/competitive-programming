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
 
const int LOGMAX = 31;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> freq(LOGMAX);
    vector<vector<int>> ind(LOGMAX);

    for(int i = 0; i < n; ++i){
        int last_index = -1;
        for(int k = 0; k < LOGMAX; ++k){
            if(1 & (a[i] >> k)){
                ++freq[k];
                last_index = k;
            }
        }
        if(last_index != -1){
            ind[last_index].push_back(i);
        }
    }

    int cnt = 0;
    for(int i = 0; i < LOGMAX; ++i){
        cnt += (freq[i] > 0);
    }
    int res = 0;

    for(int k = LOGMAX - 1; k >= 0; --k){
        if(freq[k] == 0){
            continue;
        }
        if(k + 1 == cnt){
            break;
        }
        for(int i: ind[k]){
            ++res;
            for(int p = 0; p < LOGMAX; ++p){
                if(1 & (a[i] >> p)){
                    --freq[p];
                    if(freq[p] == 0){
                        --cnt;
                    }
                }
            }
        }
    }

    cout << res << '\n';
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
 
