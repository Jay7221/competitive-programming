#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define prep(a) a.clear();	a.resize(n);
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
ll gcd(ll a, ll b){
	while(b){
		ll tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
ll lcm(ll a, ll b){
	return (a * b) / gcd(a, b);
}
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> p(n);
	for(int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;
		--tmp;
		p[i] = tmp;
	}
	vector<bool> vis(n);
	vector<vector<int> > cycles;
	vector<int> cur;
	for(int i = 0; i < n; ++i){
		if(vis[i])
			continue ;
		int k = i;
		while(!vis[k]){
			vis[k] = 1;
			cur.push_back(k);
			k = p[k];
		}
		cycles.push_back(cur);
		cur.clear();
	}
	ll ans = 1;
	for(auto cycle : cycles){
		int sz = cycle.size();
		bool done = 0;
		for(int r = 1; r < n; ++r){
			bool flag = 1;
			for(int i = 0; i < sz; ++i){
				int j = cycle[i], k = cycle[(i + r) % sz];
				if(s[j] != s[k]){
					flag = 0;
					break;
				}
			}
			if(flag){
				ans = lcm(ans, r);
				done = 1;
				break ;
			}
		}
		if(!done){
			ans = lcm(ans, sz);
		}
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}