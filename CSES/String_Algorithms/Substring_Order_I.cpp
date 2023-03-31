#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<ll> v){
	for(ll elem : v){
		cerr << elem << ' ' ;
	}
	cerr << '\n';
}
class SuffixAutomaton{
	public:
		vector<map<char, int>> edges;
		vector<int> link;
		vector<int> length;
		vector<ll> dp;
		vector<bool> vis;
		int n;
		void print(){
			for(int i = 0; i < n; ++i){
				for(auto [ch, v] : edges[i]){
					cerr << i << ' ' << v << ' ' << ch << '\n';
				}
			}
		}
		SuffixAutomaton(string s){
			// initial node
			edges.push_back(map<char, int>());
			link.push_back(-1);
			length.push_back(0);
			int last = 0;

			for(int i = 0; i < s.size(); ++i){
				// create node r
				edges.push_back(map<char, int>());
				link.push_back(0);
				length.push_back(i + 1);
				int r = edges.size() - 1;

				int p = last;
				while(p != -1 && edges[p].find(s[i]) == edges[p].end()){
					edges[p][s[i]] = r;
					p = link[p];
				}

				if(p != -1){
					int q = edges[p][s[i]];
					if(length[p] + 1 == length[q]){
						link[r] = q;
					}else{
						edges.push_back(edges[q]);
						link.push_back(link[q]);
						length.push_back(length[p] + 1);

						int qq = edges.size() - 1;

						link[r] = qq;
						link[q] = qq;

						while(p != -1 && edges[p][s[i]] == q){
							edges[p][s[i]] = qq;
							p = link[p];
						}
					}
				}
				last = r;
			}
			n = edges.size();
			dp.assign(n, 0);
			vis.assign(n, false);
			dfs(0);
		}
		string get(ll k){
			string s;
			int u = 0;
			while(k > 0){
				for(auto [ch, v] : edges[u]){
					if(dp[v] + 1 < k){
						k -= dp[v] + 1;
					}else{
						--k;
						s.push_back(ch);
						u = v;
						break;
					}
				}
			}
			return s;
		}
		void dfs(int u){
			if(!vis[u]){
				vis[u] = true;
				for(auto [ch, v] : edges[u]){
					if(!vis[v]){
						dfs(v);
					}
					dp[u] += dp[v] + 1;
				}
			}
		}
};
void solve(){
	string s;
	cin >> s;
	ll k;
	cin >> k;
	SuffixAutomaton sa(s);
	cout << sa.get(k) << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--){
		solve();
	}

	return 0;
}
