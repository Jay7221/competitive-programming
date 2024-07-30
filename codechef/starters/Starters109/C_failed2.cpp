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
 
 
bool solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> colorA(n), colorB(n);
    // elements[i] = multiset of elements of this color
    map<int, vector<int>> elements;
    map<int, int> index;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> colorA[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> colorB[i];
    }

    for(int i = 0; i < n; ++i){
        elements[colorA[i]].push_back(a[i]);
        elements[colorB[i]].push_back(b[i]);
    }

    for(auto &[key, v] : elements){
        sort(v.begin(), v.end());
    }

    int cur = -1;
    for(int i = 0; i < n; ++i){
        int c = colorA[i];
        while(index[c] < (int)elements[c].size()){
            if(elements[c][index[c]] >= cur){
                break;
            }
            ++index[c];
        }
        if(index[c] == (int)elements[c].size()){
            return false;
        }
        cur = elements[c][index[c]];
        ++index[c];
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
 
