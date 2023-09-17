#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
// Use mt19937_64 for 64 bit random numbers.
 
 
int query(int x){
    cout << "? " << x << endl;
    int y;
    cin >> y;
    return y;
}
void answer(int x){
    cout << "! " << x << endl;
}
void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int ind = 1;
    while(ind + k - 1 <= n){
        ans ^= query(ind);
        if(ind + 2 * k - 1 <= n){
            ind += k;
        }
        else{
            break;
        }
    }
    int req = n - k + 1;
    int diff = req - ind;
    diff /= 2;
    ind += diff;
    ans ^= query(ind) ;
    ind += diff;
    ans ^= query(ind) ;

    answer(ans);
}
 
int main() {
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        solve();
    }
    
    return 0;
}
 
