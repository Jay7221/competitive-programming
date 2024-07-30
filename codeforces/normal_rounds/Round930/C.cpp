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
 
int compare(int a, int b, int c, int d){
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    char res;
    cin >> res;
    if(res == '<'){
        return -1;
    }
    else if(res == '='){
        return 0;
    }
    else{
        return 1;
    }
}
void answer(int ind1, int ind2){
    cout << "! " << ind1 << ' ' << ind2 << endl;
}
 
int compare(int ind1, int ind2){
    return compare(ind1, ind1, ind2, ind2);
}
void solve() {
    int n;
    cin >> n;

    int mx = 0;
    for(int i = 1; i < n; ++i){
        if(compare(mx, i) == -1){
            mx = i;
        }
    }

    vector<int> v;
    for(int i = 0; i < n; ++i){
        if(i == mx){
            continue;
        }
        if(v.empty()){
            v.push_back(i);
        }
        else{
            int res = compare(v.back(), mx, i, mx);
            if(res == -1){
                v.clear();
                v.push_back(i);
            }
            if(res == 0){
                v.push_back(i);
            }
        }
    }


    int mn = v.back();
    for(int elem: v){
        if(compare(mn, elem) == 1){
            mn = elem;
        }
    }

    answer(mn, mx);
}
 
int main() {
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        solve();
    }
    
    return 0;
}
 
