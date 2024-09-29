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
 
vector<int> numberCars(int n, vector<vector<int>> &ranges){
    set<pair<int, bool>> st;
    vector<int> res;

    for(int i = 0; i < n; ++i){
        int l = ranges[i][0];
        int r = ranges[i][1];

        int cars = r - l + 1;

        auto it = st.lower_bound({l, false});

        int prevInd = l;
        bool isOpen = false;

        while((it != st.end()) && (it -> first <= r)){
            if(it -> second){
                cars -= it -> first - prevInd + 1;
                prevInd = it -> first;
                isOpen = false;
            }
            else{
                prevInd = it -> first;
                isOpen = true;
            }
            st.erase(it);
            it = st.lower_bound({l, false});
        }

        if(isOpen){
            cars -= r - prevInd + 1;
        }

        res.push_back(cars);

        st.insert({l, false});
        st.insert({r, true});
    }

    return res;
}
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ranges(n, vector<int>(2));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2; ++j){
            cin >> ranges[i][j];
        }
    }

    for(int elem: numberCars(n, ranges)){
        cout << elem << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
