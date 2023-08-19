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
 
 
struct Elem{
    int id, val;
    friend ostream& operator<<(ostream& out, const Elem &e){
        out << e.val;
        return out;
    };
};
void solve() {
    int n;
    cin >> n;
    vector<Elem> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a.begin(), a.end(),
            [](Elem a, Elem b){
                return (a.val < b.val);
            }
        );
    vector<int> b(n);
    bool flag = true;
    int l = 0, r = n - 1;
    int delta = 0;
    int sz = n;
    int cur = n;
    while(l <= r){
        if(((a[l].val - delta) == 0) && ((a[r].val - delta) == sz)){
            flag = false;
            break;
        }
        if(((a[l].val - delta) != 0) && ((a[r].val - delta) != sz)){
            flag = false;
            break;
        }
        if(a[l].val - delta == 0){
            b[a[l].id] = -cur;
            ++l;
        }
        else{
            b[a[r].id] = cur;
            ++delta;
            --r;
        }
        --cur;
        --sz;
    }
    if(flag){
        cout << "YES\n";
        for(int elem : b){
            cout << elem << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "NO\n";
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
 
