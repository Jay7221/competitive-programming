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
 
 
const int LOGMAX = 32;
bool solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if(sum % n != 0){
        return false;
    }
    ll avg = sum / n;
    vector<int> freq(LOGMAX);
    vector<int> pos(LOGMAX);
    vector<int> neg(LOGMAX);

    auto check = [&](ll elem){
        for(int x = 0; x < LOGMAX; ++x){
            if(elem == (1ll << x)){
                ++pos[x];
                return true;
            }
            if(elem == -(1ll << x)){
                ++neg[x];
                return true;
            }
            for(int y = 0; y < LOGMAX; ++y){
                if(elem == (1ll << x) - (1ll << y)){
                    ++freq[x];
                    --freq[y];
                    return true;
                }
            }
        }
        return false;
    };

    for(ll elem : a){
        if(elem == avg){
            continue;
        }
        if(!check(elem - avg)){
            return false;
        }
    }

    /*
    cerr << freq << '\n';
    cerr << pos << '\n';
    cerr << neg << '\n';
    cerr << "\n-------------------------\n";
    */

    for(int i = LOGMAX - 1; i > 0; --i){
        if((pos[i] < 0) || (neg[i] < 0)){
            return false;
        }
        int diff = freq[i] + pos[i] - neg[i];
        if(diff == 0){
            continue;
        }
        if(diff > 0){
            neg[i] += diff;
            neg[i - 1] -= diff;
            pos[i - 1] += diff;
        }
        else{
            diff = abs(diff);
            pos[i] += diff;
            pos[i - 1] -= diff;
            neg[i - 1] += diff;
        }
    }

    for(int i = 0; i < LOGMAX; ++i){
        if((pos[i] < 0) || (neg[i] < 0)){
            return false;
        }
        if(freq[i] + pos[i] - neg[i] != 0){
            return false;
        }
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    
    return 0;
}
 
