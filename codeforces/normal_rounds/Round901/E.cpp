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
 
map<vector<int>, int> dp;
map<vector<int>, bool> vis;
const int LOGMAX = 30;
int solve() {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    map<vector<int>, int> state_map;
    state_map[{0, 0, 0}] = 0;
    state_map[{0, 1, 0}] = 1;
    state_map[{1, 0, 0}] = 2;
    state_map[{1, 1, 0}] = 3;
    state_map[{0, 0, 1}] = 4;
    state_map[{0, 1, 1}] = 5;
    state_map[{1, 0, 1}] = 6;
    state_map[{1, 1, 1}] = 7;

    state_map[{0, 0}] = 0;
    state_map[{0, 1}] = 1;
    state_map[{1, 0}] = 2;
    state_map[{1, 1}] = 3;
    vector<int> state(8, 5);
    for(int k = 0; k < LOGMAX; ++k){
        int ai = 1 & (a >> k);
        int bi = 1 & (b >> k);
        int ci = 1 & (c >> k);
        int di = 1 & (d >> k);
        int mi = 1 & (m >> k);
        int index = state_map[{ai, bi, mi}];
        int val = state_map[{ci, di}];
        if(state[index] == 5){
            state[index] = val;
        }
        if(state[index] != val){
            return -1;
        }
    }
    if(!vis[state]){
        return -1;
    }
    return dp[state];

}

void pre(){
    vector<pair<int, int>> states = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1},
    };
    map<pair<int, int>, int> state_id;
    state_id[{0, 0}] = 0;
    state_id[{0, 1}] = 1;
    state_id[{1, 0}] = 2;
    state_id[{1, 1}] = 3;
    auto operate0 = [&](int type, int state){
        int x, y;
        tie(x, y) = states[state];
        if(type == 0){
            x &= y;
        }
        else if(type == 1){
            x |= y;
        }
        else if(type == 2){
            y ^= x;
        }
        else if(type == 3){
            y ^= 0;
        }
        return state_id[{x, y}];
    };
    auto operate1 = [&](int type, int state){
        int x, y;
        tie(x, y) = states[state];
        if(type == 0){
            x &= y;
        }
        else if(type == 1){
            x |= y;
        }
        else if(type == 2){
            y ^= x;
        }
        else if(type == 3){
            y ^= 1;
        }
        return state_id[{x, y}];
    };
    auto operate = [&](int type, vector<int> v){
        for(int i = 0; i < 4; ++i){
            v[i] = operate0(type, v[i]);
        }
        for(int i = 4; i < 8; ++i){
            v[i] = operate1(type, v[i]);
        }
        return v;
    };
    queue<vector<int>> q;
    vector<int> start_state = {0, 1, 2, 3, 0, 1, 2, 3};
    q.push(start_state);
    vis[start_state] = true;
    dp[start_state] = 0;
    vector<vector<int>> all_states;
    while(!q.empty()){
        vector<int> cur_state = q.front();
        all_states.push_back(cur_state);
        q.pop();
        for(int type = 0; type < 4; ++type){
            vector<int> next_state = operate(type, cur_state);
            if(!vis[next_state]){
                q.push({next_state});
                vis[next_state] = true;
                dp[next_state] = dp[cur_state] + 1;
            }
        }
    }
    vector<int> special_state = {0, 5, 5, 1, 5, 5, 5, 2};
    function<void(vector<int>&, int, int)> dfs;
    dfs = [&](vector<int> &state, int index, int value){
        if(index == state.size()){
            if(!vis[state]){
                vis[state] = true;
                dp[state] = value;
            }
            else{
                dp[state] = min(dp[state], value);
            }
            return;
        }
        int tmp = 5;
        swap(state[index], tmp);
        dfs(state, index + 1, value);
        swap(state[index], tmp);
        dfs(state, index + 1, value);
    };
    for(auto state : all_states){
        dfs(state, 0, dp[state]);
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    pre();
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << solve() << '\n';
    }
    
    return 0;
}
 
