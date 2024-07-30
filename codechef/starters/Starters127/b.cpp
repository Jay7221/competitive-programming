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
    string a, b;
    cin >> a >> b;

    int cnta = count(a.begin(), a.end(), 'a');
    int cntb = count(a.begin(), a.end(), 'b');
    int cntc = count(a.begin(), a.end(), 'c');

    if(count(b.begin(), b.end(), 'a') != cnta){
        return false;
    }
    if(count(b.begin(), b.end(), 'b') != cntb){
        return false;
    }
    if(count(b.begin(), b.end(), 'c') != cntc){
        return false;
    }

    for(int i = 0; i < n; ++i){
        if((a[i] != b[i]) && ((a[i] == 'b') || (b[i] == 'b'))){
            return false;
        }
    }

    int cnt = 0;
    for(int l = 0, r = 0; l < n; ++l){
        if(a[l] == b[l]){
            cnt -= (a[l] == 'b');
        }
        else{
            while(r < n){
                if(a[r] == b[r]){
                    cnt += (a[r] == 'b');
                    ++r;
                }
                else if(a[r] == 'c'){
                    break;
                }
                else{
                    ++r;
                }
            }
            if(r < n && (cnt > 0) && (a[l] == 'a') && (a[r] == 'c')){
                swap(a[l], a[r]);
            }
            else{
                return false;
            }
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
 
