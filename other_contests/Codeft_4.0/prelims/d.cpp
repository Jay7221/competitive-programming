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
 
const int MAX = 1e6 + 1;

vector<int> primes;
void pre(){
    vector<bool> isPrime(MAX, true);
    for(int i = 2; i <= MAX; ++i){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = 2; i * j < MAX; ++j){
                isPrime[i * j] = false;
            }
        }
    }
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> freq(MAX);
    // freq[i] = number of breeds that container with capacity i can have

    for(int elem: a){
        for(int d = 1; d * d <= elem; ++d){
            if(elem % d == 0){
                ++freq[d];
                if(d * d != elem){
                    ++freq[elem / d];
                }
            }
        }
    }
    vector<vector<int>> kvals(n + 1);
    for(int i = 0; i < MAX; ++i){
        if(freq[i] > 0){
            kvals[freq[i]].push_back(i);
        }
    }


    while(q--){
        int k, l, r;
        cin >> k >> l >> r;
        auto it = upper_bound(kvals[k].begin(), kvals[k].end(), r);
        if(it == kvals[k].begin()){
            cout << -1 << ' ';
        }
        else{
            --it;
            if(*it < l){
                cout << -1 << ' ';
            }
            else{
                cout << *it << ' ';
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
