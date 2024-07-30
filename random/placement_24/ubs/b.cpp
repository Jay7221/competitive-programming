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
 
 
long findMaximumEarning(vector<int> send, vector<int> receive, vector<int> amount, vector<int> capacity){
    int n = send.size();
    int m = capacity.size();

    vector<vector<int>> task(n, vector<int>(2));
    for(int i = 0; i < n; ++i){
        task[i][0] = amount[i];
        task[i][1] = max(send[i], receive[i]);
    }
    sort(task.rbegin(), task.rend());
    sort(capacity.begin(), capacity.end());

    long ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(capacity[j] >= task[i][1]){
                capacity[j] = -1;
                ans += task[i][0];
                break;
            }
        }
    }

    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<int> send(n), receive(n), amount(n), capacity(m);
    for(int i = 0; i < n; ++i){
        cin >> send[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> receive[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> amount[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> capacity[i];
    }

    cout << findMaximumEarning(send, receive, amount, capacity) << '\n';
    
    return 0;
}
 
