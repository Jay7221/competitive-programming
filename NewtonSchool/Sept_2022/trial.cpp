#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
void solve(){
	auto input = [&](pair<int, int> &p){
		cin >> p.first >> p.second;
	};
	auto output = [&](pair<int, int> &p){
		cout << p.first << ' ' << p.second ;
	};
	auto error = [&](pair<int, int> &p){
		cerr << "{" << p.first << ' ' << p.second << "}";
	};
	auto debug = [&](vector<pair<int, pair<int, int> > >& v){
		for(auto [a, b] : v){
			cerr << "{" << a << ", ";
			error(b);
			cerr << "}, ";
		}
		cerr << '\n';
	};
	int n, m, k;
	cin >> n >> m >> k;
	map<pair<int, int>, vector<pair<int, pair<int, int> >> > graph;
	vector<pair<int, int> > v;
	v.push_back({1, 1});
	v.push_back({n, m});
	vector<int> xx(n + 1);
	for(int i = 1; i <= n; ++i)
		cin >> xx[i];
	for(int i = 0; i < k; ++i){
		pair<int, int> x, y;
		input(x);
		input(y);
		int h;
		cin >> h;
		graph[x].push_back({-h, y});
		v.push_back(x);
		v.push_back(y);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size() - 1; ++i){
		int a, b, c, d;
		tie(a, b) = v[i];
		tie(c, d) = v[i + 1];
		if(a != c)
			continue ;
		if(b == d)
			continue ; 
		int h = abs(d - b) * xx[a];
		graph[v[i]].push_back({h, v[i + 1]});
		graph[v[i + 1]].push_back({h, v[i]});
	}
	map<pair<int, int>, ll> dp;
	for(auto c : v)
		dp[c] = INF;
	dp[{1, 1}] = 0;
	set<pair<ll, pair<int, int> > > s;
	for(auto p : v){
		s.insert({dp[p], p});
	}
	auto proc = [&](pair<int, int> u){
		for(auto [c, v] : graph[u]){
			if(dp[v] > c + dp[u]){
				s.erase({dp[v], v});
				dp[v] = dp[u] + c;
				s.insert({dp[v], v});
			}
		}
	};
	while(s.size()){
		int tmp;
		pair<int, int> u;
		tie(tmp, u) = *s.begin();
		s.erase(s.begin());
		if(dp[u] == INF)
			continue;
		proc(u);
	}
	if(dp[{n, m}] == INF){
		cout << "NO ESCAPE\n";
	}else{
		cout << dp[{n, m}] << '\n';
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}