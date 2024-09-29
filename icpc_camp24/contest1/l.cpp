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
 
 
pair<int, int> solve() {
    string s;
    cin >> s;
    int cntA = count(s.begin(), s.end(), 'A');
    int cntB = count(s.begin(), s.end(), 'B');
    int curA = 0, curB = 0;

    int n = s.size();
    int l = 0, r = 0;

    auto add = [&](int ind){
        if(s[ind] == 'A'){
            ++curA;
        }
        else{
            ++curB;
        }
    };
    auto shouldRemove = [&](int ind){
        if(s[ind] == 'A'){
            return (2 * curA > cntA);
        }
        else{
            return (2 * curB > cntB);
        }
    };
    auto remove = [&](int ind){
        if(s[ind] == 'A'){
            --curA;
        }
        else{
            --curB;
        }
    };

    while(r < n){
        add(r);
        ++r;

        while(l < r){
            if(shouldRemove(l)){
                remove(l);
                ++l;
            }
            else{
                break;
            }
        }

        if((2 * curA == cntA) && (2 * curB == cntB)){
            return {l + 1, r + 1};
        }
    }

    return {-1, -1};
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int l, r;
    tie(l, r) = solve();
    if(l == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        cout << l << ' ' << r << '\n';
    }
    
    return 0;
}
 
