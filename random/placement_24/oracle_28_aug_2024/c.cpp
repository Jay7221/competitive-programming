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
 
vector<int> findPodCount(vector<int> &pods, vector<vector<int>> &logs){
    int m = logs.size();
    int n = pods.size();
    vector<int> sufMax(m + 1, -1);
    for(int i = m - 1; i >= 0; --i){
        sufMax[i] = sufMax[i + 1];
        if(logs[i][0] == 2){
            sufMax[i] = max(sufMax[i], logs[i][2]);
        }
    }
    for(int i = 0; i < n; ++i){
        pods[i] = max(pods[i], sufMax[0]);
    }
    for(int i = 0; i < m; ++i){
        if(logs[i][0] == 1){
            int ind = logs[i][1] - 1;
            pods[ind] = max(logs[i][2], sufMax[i]);
        }
    }
    return pods;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> pods(n);
    for(int i = 0; i < n; ++i){
        cin >> pods[i];
    }
    int m;
    cin >> m;
    vector<vector<int>> logs(m, vector<int>(3));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> logs[i][j];
        }
    }
    for(int elem: findPodCount(pods, logs)){
        cout << elem << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
