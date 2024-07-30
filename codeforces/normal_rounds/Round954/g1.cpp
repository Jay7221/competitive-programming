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
 
vector<int> getDivisors0(int n){
    vector<int> res;
    for(int d = 1; d * d <= n; ++d){
        if(n % d == 0){
            res.push_back(d);
            if(d * d != n){
                res.push_back(n / d);
            }
        }
    }
    return res;
}
const int MAX = 5e5 + 7;
vector<int> prime(MAX, 1);

void pre(){
    for(int p = 2; p < MAX; ++p){
        if(prime[p] == 1){
            for(int j = 1; j * p < MAX; ++j){
                prime[j * p] = p;
            }
        }
    }
}

void getDivisorsHelper(int n, vector<int> &res){
    if(n == 1){
        res.push_back(1);
        return;
    }
    int p = prime[n];
    int mult = 1;
    while(prime[n] == p){
        mult *= p;
        n /= p;
    }
    getDivisorsHelper(n, res);
    int sz = res.size();
    while(mult > 1){
        for(int i = 0; i < sz; ++i){
            res.push_back(res[i] * mult);
        }
        mult /= p;
    }
}

vector<int> getDivisors(int n){
    vector<int> res;
    getDivisorsHelper(n, res);
    return res;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }

    // freq[have][need]
    vector<map<int, int>> freq(n + 1);

    ll ans = 0;

    for(int i = 0; i < n; ++i){
        int have = p[i] / gcd(i + 1, p[i]);
        int need = (i + 1) / gcd(i + 1, p[i]);

        for(int d: getDivisors(have)){
            ans += freq[d][need];
        }
        for(int d: getDivisors(have)){
            ++freq[need][d];
        }
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
 
