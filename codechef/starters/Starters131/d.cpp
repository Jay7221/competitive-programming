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
 
const int MAX = 1e7;
vector<int> largest_div(MAX, 1);
 
void pre(){
    for(int p = 2; p < MAX; ++p){
        if(largest_div[p] == 1){
            for(int j = 1; p * j < MAX; ++j){
                largest_div[p * j] = p;
            }
        }
    }
}

int get_int(vector<int> &digits, vector<int> &ind){
    int ans = 0;
    for(int i = 0; i < (int)ind.size(); ++i){
        ans = 10 * ans + digits[ind[i]];
    }
    return ans;
}

vector<int> getD(int x){
    vector<int> dspace;
    vector<int> digits;
    while(x){
        digits.push_back(x % 10);
        x /= 10;
    }
    int n = digits.size();
    vector<int> ind(n);
    for(int i = 0; i < n; ++i){
        ind[i] = i;
    }

    if(digits[ind[0]] != 0){
        dspace.push_back(get_int(digits, ind));
    }
    while(next_permutation(ind.begin(), ind.end())){
        if(digits[ind[0]] != 0){
            dspace.push_back(get_int(digits, ind));
        }
    }

    return dspace;
}

void solve() {
    int X, Y;
    cin >> X >> Y;
    map<int, bool> freq1, freq2;
    for(int x: getD(X)){
        while(x > 1){
            freq1[largest_div[x]] = true;
            x /= largest_div[x];
        }
    }
    for(int y: getD(Y)){
        while(y > 1){
            freq2[largest_div[y]] = true;
            y /= largest_div[y];
        }
    }
    int ans = 1;
    for(auto [p, f]: freq1){
        if(freq2[p]){
            ans = p;
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
 
