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
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
 
void query(vector<int> a){
    cout << "- " << a.size() << " ";
    for(int elem : a){
        ++elem;
        cout << elem << " ";
    }
    cout << endl;
}
void answer(int ind){
    ++ind;
    cout << "! " << ind << endl;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prev(10, n + 1);
    auto check = [&](int obj){
        return ((1 <= obj) && (obj <= 9));
    };
    vector<int> v;
    for(int stage = 0; stage < 5; ++stage){
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        vector<int> freq(10);
        for(int i = 0; i < n; ++i){
            if(!check(a[i])){
                answer(i);
                return;
            }
            ++freq[a[i]];
        }

        for(int type = 0; type < 10; ++type){
            if(freq[type] > prev[type]){

                if(freq[type] == 1){
                    for(int index = 0; index < n; ++index){
                        if(a[index] == type){
                            answer(index);
                            return;
                        }
                    }
                }

                for(int index = 0; index < 10; ++index){
                    if(index != type){
                        freq[index] = 0;
                    }
                }
                for(int index = 0; index < n; ++index){
                    if(a[index] != type){
                        v.push_back(index);
                    }
                }
                break;
            }
        }

        prev = freq;
        query(v);
        n -= v.size();
        v.clear();
        a.resize(n);
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
 
