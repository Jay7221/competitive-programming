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
 
bool isPrime(int n){
    if(n == 1){
        return false;
    }
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int mex(vector<int> v){
    sort(v.begin(), v.end());
    int res = 1;
    for(int elem: v){
        if(elem == res){
            ++res;
        }
    }
    return res;
}
void solve() {
    int n;
    cin >> n;

    if(n < 6){
        vector<int> color(n, 1);
        for(int i = 1; i < n; ++i){
            vector<int> v;
            for(int j = 0; j < i; ++j){
                if(isPrime((i + 1) ^ (j + 1))){
                    v.push_back(color[j]);
                }
            }
            color[i] = mex(v);
        }
        cout << *max_element(color.begin(), color.end()) << '\n';
        for(int elem: color){
            cout << elem << ' ';
        }
        cout << '\n';
    }
    else{
        cout << 4 << '\n';
        for(int i = 0; i < n; ++i){
            cout << 1 + (i % 4) << ' ';
        }
        cout << '\n';
    }

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
 
