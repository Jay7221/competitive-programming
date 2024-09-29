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
 
int getL(int n){
    int l = n;
    for(int k = 0; k < 31; ++k){
        if(1 & (l >> k)){
            l ^= (1 << k);
            return l;
        }
    }
    return 1;
}
vector<int> perm(int n){
    vector<int> res;

    if(n & 1){ // n is odd
        res = {2, 3, 1};
        for(int i = 4; i < n; i += 2){
            res.push_back(i + 1);
            res.push_back(i);
        }
        return res;
    }

    if(((n - 1) & n) == 0){ // n is a power of 2, last elem is the only one with Max set bit
        res.push_back(n);
        for(int i = 2; i < n; i += 2){
            res.push_back(i + 1);
            res.push_back(i);
        }
        res.push_back(1);
        return res;
    }


    res = {2, 3, 1};
    if(n % 4 == 0){
        int l = getL(n);
        for(int i = 4; i < l; i += 2){
            res.push_back(i + 1);
            res.push_back(i);
        }


        res.push_back(n);
        res.push_back(l + 3);
        res.push_back(l + 1);
        res.push_back(l + 2);
        for(int i = l + 4; i < n; i += 2){
            res.push_back(i + 1);
            res.push_back(i);
        }
        res.push_back(l);
    }
    else{
        for(int i = 4; i < n - 2; i += 2){
            res.push_back(i + 1);
            res.push_back(i);
        }

        res.push_back(n - 1);
        res.push_back(n);
        res.push_back(n - 2);
    }


    return res;
}

int check(int n, vector<int> p){
    int res = 0;
    assert((int)p.size() == n);
    for(int i = 1; i <= n; ++i){
        res = max(res, i ^ p[i - 1]);
        assert(i != p[i - 1]);
    }
    return res;
}
 
void solve() {
    int n;
    cin >> n;
    for(int elem: perm(n)){
        cout << elem << ' ';
    }
    cerr << check(n, perm(n)) << '\n';
    cout << '\n';
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
 
