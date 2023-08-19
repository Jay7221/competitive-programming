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
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> v;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == 2){
            while(!v.empty()){
                if(v.back() == 0){
                    break;
                }
                v.pop_back();
            }
            while((i + 1 < n) && (a[i + 1] != 0)){
                ++i;
            }
            v.push_back(2);
        }
        else if(a[i] == 1){
            v.push_back(1);
            while((i + 1 < n) && (a[i + 1] == 1)){
                ++i;
            }
        }
        else{
            v.push_back(0);
        }
    }
    a = v;
    n = a.size();
    v.clear();
    /*
    int cnt0 = count(a.begin(), a.end(), 0);
    int cnt1 = count(a.begin(), a.end(), 1);
    ans += max(cnt0, cnt1);
    */
    for(int i = 0; i < n; ++i){
        if(a[i] == 2){
            if(i - 1 > -1){
                a[i - 1] = -1;
            }
            if(i + 1 < n){
                a[i + 1] = -1;
            }
            a[i] = -1;
            ++ans;
        }
    }
    for(int i = 0; i < n; ++i){
        if(a[i] == 1){
            if((i - 1 > -1) && (a[i - 1] != -1)){
                a[i - 1] = -1;
            }
            else if((i + 1 < n) && (a[i + 1] != -1)){
                a[i + 1] = -1;
            }
            a[i] = -1;
            ++ans;
        }
    }
    for(int i = 0; i < n; ++i){
        if(a[i] != -1){
            ++ans;
        }
    }
    ans += v.size();
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
