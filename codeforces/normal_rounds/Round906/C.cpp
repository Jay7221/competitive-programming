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
 
 
void solve() {
    int n;
    cin >> n;
    deque<int> s;
    int valid = 0;
    for(int i = 0; i < n; ++i){
        char ch;
        cin >> ch;
        int digit = ch - '0';
        s.push_back(digit);
        valid += 2 * digit - 1;
    }
    if(valid != 0){
        cout << -1 << '\n';
        return;
    }
    vector<int> operations;


    int l = 0;

    while(!s.empty()){
        if(s.front() != s.back()){
            s.pop_front();
            s.pop_back();
        }
        else if(s.front() == 0){
            operations.push_back(l + s.size());
            s.push_back(s.front());
            s.pop_front();
        }
        else{
            operations.push_back(l);
            s.push_front(s.back());
            s.pop_back();
        }
        ++l;
    }



    cout << operations.size() << '\n';
    for(int ind : operations){
        cout << ind << ' ';
    }
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
 
