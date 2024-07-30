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
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "#" + s;

    vector<ll> prex(n + 2), prey(n + 2);
    vector<ll> sufx(n + 2), sufy(n + 2);

    for(ll i = 1; i <= n; ++i){
        prex[i] = prex[i - 1];
        prey[i] = prey[i - 1];
        if(s[i] == 'U'){
            ++prey[i];
        }
        else if(s[i] == 'D'){
            --prey[i];
        }
        else if(s[i] == 'L'){
            --prex[i];
        }
        else{
            ++prex[i];
        }
    }

    for(ll i = n; i > 0; --i){
        sufx[i] = sufx[i + 1];
        sufy[i] = sufy[i + 1];
        if(s[i] == 'U'){
            ++sufy[i];
        }
        else if(s[i] == 'D'){
            --sufy[i];
        }
        else if(s[i] == 'L'){
            --sufx[i];
        }
        else{
            ++sufx[i];
        }
    }

    map<pair<ll, ll>, set<ll>> prei, sufi;
    for(ll i = 1; i <= n; ++i){
        prei[{prex[i], prey[i]}].insert(i);
        sufi[{sufx[i], sufy[i]}].insert(i);
    }


    while(q--){
        ll x, y, l, r;
        cin >> x >> y >> l >> r;

        pair<ll, ll> p = {x, y};
        bool flag = ((x == 0) && (y == 0));

        if(!prei[p].empty()){
            if(*prei[p].begin() < l){
                flag = true;
            }
            if(*(--prei[p].end()) >= r){
                flag = true;
            }
        }

        x = x - prex[l - 1] + sufx[r + 1];
        y = y - prey[l - 1] + sufy[r + 1];
        p = {x, y};

        if(!sufi[p].empty()){
            auto lb = sufi[p].lower_bound(l);
            if((lb != sufi[p].end()) && (*lb <= r)){
                flag = true;
            }
        }

        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
