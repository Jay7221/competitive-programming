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
 
 
void test(int k, vector<int> a){
    int n = a.size();
    cout << n << ' ' << k << endl;
    int ans = 0;
    for(int elem : a){
        ans ^= elem;
    }
    while(true){
        char type;
        int x;
        cin >> type >> x;
        if(type == '?'){
            int ret = 0;
            --x;
            for(int i = x; i < x + k; ++i){
                ret ^= a[i];
            }
            reverse(a.begin() + x, a.begin() + x + k);
            cout << ret << endl;
        }
        else{
            if(x == ans){
                cerr << "CORRECT" << endl;
            }
            else{
                cerr << "WRONG" << endl;
            }
            break;
        }
    }
}
 
int main() {
    vector<pair<int, vector<int>>> v = {
        {2, {4, 2, 5, 1}},
        {6, {5, 7, 1, 3, 3, 7}},
    };
    cout << v.size() << endl;
    for(auto [k, a] : v){
        test(k, a);
    }
    
    return 0;
}
 
