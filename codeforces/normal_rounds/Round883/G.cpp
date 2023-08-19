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
 
vector<long long> dijkstra(int s, vector<vector<pair<int, int>>> graph){
	const ll INF = 1e15 + 7;
	int n = graph.size();
	vector<long long> d(n, INF);
	vector<int> par(n, -1);
	d[s] = 0;
	set<pair<long long, int>> st;
	for(int i = 0; i < n; ++i){
		st.insert({d[i], i});
	}
	auto scan = [&](int u){
		for(auto [v, w] : graph[u]){
			if(d[v] > d[u] + w){
				st.erase({d[v], v});
				d[v] = d[u] + w;
				par[v] = u;
				st.insert({d[v], v});
			}
		}
	};
	while(st.size()){
		int u, du;
		tie(du, u) = *st.begin();
		st.erase(st.begin());
		scan(u);
	}
	return d;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    int root = 0;
    for(int i = n - 1; i >= 0; --i){
        char ch;
        cin >> ch;
        if(ch == '1'){
            root |= (1 << i);
        }
    }
    int N = (1 << n);
    vector<vector<pair<int, int>>> graph(N);
    for(int i = 0; i < m; ++i){
        int cure = 0, sideEffect = 0;
        int d;
        cin >> d;
        for(int i = n - 1; i >= 0; --i){
            char ch;
            cin >> ch;
            if(ch == '1'){
                cure |= (1 << i);
            }
        }
        for(int i = n - 1; i >= 0; --i){
            char ch;
            cin >> ch;
            if(ch == '1'){
                sideEffect |= (1 << i);
            }
        }
        for(int i = 0; i < N; ++i){
            int j = (((i | cure) ^ cure) | sideEffect);
            graph[i].push_back({j, d});
        }
    }
    vector<ll> d = dijkstra(root, graph);
    ll ans = (d[0] < INF) ? d[0] : -1;
    cout << ans << '\n';
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
 
