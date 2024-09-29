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
 
const int MAX_N = 2e5 + 7;
const int MAX_BASE = 101;

int a[MAX_N];
int pre[MAX_N][MAX_BASE];
int firstInd[MAX_N][MAX_BASE];
int level[MAX_N][MAX_BASE];

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    int base = min(n, MAX_BASE - 1);

    for(int i = 0; i <= n; ++i){
        for(int level = 0; level <= base; ++level){
            pre[i][level] = 0;
        }
    }

    for(int level = 0; level <= base; ++level){
        for(int sum = 0; sum <= 2 * n; ++sum){
            firstInd[level][sum] = n + 1;
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int level = 1; level < base; ++level){
            pre[i][level] = pre[i - 1][level] + (a[i] >= level);
            if(pre[i][level] > pre[i - 1][level]){
                firstInd[level][pre[i][level]] = i;
            }
        }
    }

    for(int i = 0; i <= n; ++i){
        for(int k = 0; k <= base; ++k){
            level[i][k] = 1;
        }
    }

    for(int k = 1; k < base; ++k){
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            level[i][k] = level[i - 1][k];
            if(cnt == k){
                ++level[i][k];
                cnt = 0;
            }
            cnt += (level[i][k] <= a[i]);
        }
    }

    auto check = [&](int i, int k){
        if(k < base){
            return (level[i][k] <= a[i]);
        }
        else{
            int ind = 0;
            int curLevel = 1;
            while(curLevel <= a[i]){
                if(pre[ind][curLevel] + k > n){
                    return true;
                }
                ind = firstInd[curLevel][pre[ind][curLevel] + k];
                if(ind >= i){
                    return true;
                }
                ++curLevel;
            }
            return false;
        }
    };

    while(q--){
        int i, x;
        cin >> i >> x;

        if(check(i, x)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
