#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Hash{
	public:
		ll MOD = 1e9 + 7;
		int a = 1e7 + 2;
		int h = 33;
		int add(int a, int b){
			ll aa = a, bb = b;
			return ((aa + bb) % MOD);
		}
		int mult(int a, int b){
			ll aa = a, bb = b;
			return ((aa * bb) % MOD);
		}
		int power(int a, int p){
			int ans = 1, rem = a;
			while(p){
				if(p & 1){
					ans = mult(ans, rem);
				}
				rem = mult(rem, rem);
				p >>= 1;
			}
			return ans;
		}
		int hash(int x){
			return power(add(x, a), h);
		}
		int hash(vector<int> v){
			int ans = 0;
			for(int i : v){
				ans = add(ans, hash(i));
			}
			ans = hash(ans);
			return ans;
		}
};
vector<vector<int>> graph;
vector<int> h;
vector<bool> isSym;
Hash H;
void print(vector<int> v){
	for(int u : v){
		cerr << u + 1 << ' ' ;
	}
	cerr << '\n';
}
int n;
void dfs(int u, int p){
	int sz = graph[u].size();
	vector<int> s;
	for(int v : graph[u]){
		if(v != p){
			dfs(v, u);
			s.push_back(h[v]);
		}
	}
	h[u] = H.add(h[u], H.hash(s));
	h[u] = H.power(h[u], s.size());

	multiset<int> m;
	for(int v : graph[u]){
		if(v != p){
			if(m.find(h[v]) != m.end()){
				m.erase(m.find(h[v]));
			}else{
				m.insert(h[v]);
			}
		}
	}
	if(m.size() == 0){
		isSym[u] = true;
	}else{
		if(m.size() == 1){
			int k = *m.begin();
			isSym[u] = false;
			for(int v : graph[u]){
				if(v != p){
					if(h[v] == k){
						isSym[u] = (isSym[u] | isSym[v]);
					}
				}
			}
		}else{
			isSym[u] = false;
		}
	}
}
void solve(){
	cin >> n;
	graph.assign(n, vector<int>());
	h.assign(n, 3);
	isSym.assign(n, true);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, -1);
	if(isSym[0]){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
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

	return 0;
}
