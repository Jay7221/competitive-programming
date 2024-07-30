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
 
 
const int MAX = 3500;
vector<int> primes;
void pre(){
    vector<bool> isPrime(MAX, true);
    for(int i = 2; i < MAX; ++i){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = 2; i * j < MAX; ++j){
                isPrime[i * j] = false;
            }
        }
    }
}
vector<int> find_oddp(int n){
    vector<int> ans;
    for(int p : primes){
        if(p * p > n){
            break;
        }
        int freq = 0;
        while(n % p == 0){
            n /= p;
            ++freq;
        }
        if(freq & 1){
            ans.push_back(p);
        }
    }
    if(n > 1){
        ans.push_back(n);
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    map<vector<int>, int> freq;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        vector<int> odd_p = find_oddp(a);
        if(!odd_p.empty()){
            ++freq[odd_p];
        }
    }
    int ans = 0;
    for(auto [odd_p, f] : freq){
        ans = max(ans, f);
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
