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
 
int query(string t){
    cout << "? " << t << endl;
    int res;
    cin >> res;
    return res;
}

void answer(string s){
    cout << "! " << s << endl;
}

string fill_back(string s, int n){
    while((int)s.size() < n){
        s.push_back('0');
        if(query(s) == 0){
            s.back() = '1';
            if(query(s) == 0){
                s.pop_back();
                return s;
            }
        }
    }
    return s;
}

string fill_front(string s, int n){
    while((int)s.size() < n){
        s = "0" + s;
        if(query(s) == 0){
            s[0] = '1';
            if(query(s) == 0){
                reverse(s.begin(), s.end());
                s.pop_back();
                reverse(s.begin(), s.end());
                return s;
            }
        }
    }
    return s;
}

 
void solve() {
    int n;
    cin >> n;

    if(n == 1){
        if(query("0") == 1){
            answer("0");
        }
        else{
            answer("1");
        }
    }
    else{
        string s = fill_back("0", n);
        s = fill_front(s, n);

        if(s.size() == 1){
            s.clear();
            for(int i = 0; i < n; ++i){
                s.push_back('1');
            }
        }

        answer(s);
    }

}
 
int main() {

    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
