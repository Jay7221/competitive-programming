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
 
 
#define pii  pair<int, int>
vector<int> solve(int A, vector<vector<int>> &b){
    int m = b.size();
    vector<int> start(m + 1), end(m + 1), dur(m + 1);
    for(int i = 0; i < m; ++i){
        start[i + 1] = b[i][0];
        end[i + 1] = b[i][1];
        dur[i + 1] = b[i][2];
    }
    priority_queue<pii, vector<pii>, greater<pii>> pqs, pqe;
    for(int i = 1; i <= m; ++i){
        pqs.push({start[i], i});
    }
    vector<int> ans(A + 1);
    ans[0] = -1;
    bool isPossible = true;
    for(int day = 1; day <= A; ++day){
        while(!pqs.empty() && (pqs.top().first <= day)){
            int id, _;
            tie(_, id) = pqs.top();
            pqs.pop();
            pqe.push({end[id], id});
        }
        if(ans[day] == m + 1){
            continue;
        }
        if(!pqe.empty()){
            int id, _;
            tie(_, id) = pqe.top();
            pqe.pop();
            ans[day] = id;
            if(end[id] < day){
                isPossible = false;
                break;
            }
            --dur[id];
            if(dur[id] != 0){
                pqe.push({end[id], id});
            }
        }
    }
    if(!pqe.empty() || !pqs.empty()){
        isPossible = false;
    }
    if(!isPossible){
        ans.assign(1, -1);
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int A, M;
    cin >> A >> M;
    vector<vector<int>> B(M, vector<int>(3));
    for(int i = 0; i < M; ++i){
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }
    for(int elem : solve(A, B)){
        cout << elem << ' ';
    }
    cout << '\n';
    
    return 0;
}
 
