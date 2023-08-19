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
 
 
void print(vector<int> arr){
    for(int elem : arr){
        cout << elem << ' ';
    }
    cout << endl;
}
bool testcase(int n, int k, vector<int> arr){
    --k;
    int val = arr[k];
    cout << n << endl;
    for(int q = 0; q < 5; ++q){
        print(arr);
        char ch; 
        cin >> ch;
        if(ch == '-'){
            int sz;
            cin >> sz;

            vector<bool> vis(n);
            for(int i = 0; i < sz; ++i){
                int ind;
                cin >> ind;
                --ind;
                vis[ind] = true;
            }

            vector<int> narr;
            for(int i = 0; i < n; ++i){
                if(!vis[i]){
                    narr.push_back(arr[i]);
                }
            }
            arr = narr;
            n -= sz;

            bool flag = false;
            for(int i = 0; i < n; ++i){
                if(arr[i] == val){
                    k = i;
                    flag = true;
                    ++arr[i];
                    val = arr[i];
                    break;
                }
            }
            if(!flag){
                return false;
            }
        }
        else if(ch == '!'){
            int kk;
            cin >> kk;
            --kk;
            return (kk == k);
        }
        else{
            return false;
        }
    }
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 3;
    cout << t << endl;
    vector<int> n = {5, 8, 15};
    vector<int> k = {3, 1, 10};
    vector<vector<int>> arr = {{1, 1, 2, 2, 3}, {1, 2, 3, 4, 3, 4, 2, 1}, {1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1}};
    for(int i = 0; i < t; ++i){
        if(!testcase(n[i], k[i], arr[i])){
            cout << "WRONG" << endl;
            return 0;
        }
    }
    cout << "CORRECT" << endl;
    return 0;
}
 
