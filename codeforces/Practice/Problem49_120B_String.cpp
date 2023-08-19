#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
class SuffixAutomaton{
	public:	
		vector<map<char, int> > edges;
		vector<int> length;
		vector<int> terminals;
		vector<int> link;
		int last;
		int n;
		vector<int> words, occurences;
		vector<bool> isTerminal;
		SuffixAutomaton(string s){
			edges.push_back(map<char, int>());
			length.push_back(0);
			link.push_back(-1);
			last = 0;
			for(int i = 0; i < s.size(); ++i){
				edges.push_back(map<char, int>());
				length.push_back(i + 1);
				link.push_back(0);

				int r = edges.size() - 1;

				int p = last;
				while((p >= 0) && (edges[p].find(s[i]) == edges[p].end())){
					edges[p][s[i]] = r;
					p = link[p];
				}
				if(p != -1){
					int q = edges[p][s[i]];
					if(length[p] + 1 == length[q]){
						link[r] = q;
					}else{
						edges.push_back(edges[q]);
						length.push_back(length[p] + 1);
						link.push_back(link[q]);
						int qq = edges.size() - 1;

						link[q] = qq;
						link[r] = qq;

						while((p >= 0) && (edges[p][s[i]] == q)){
							edges[p][s[i]] = qq;
							p = link[p];
						}
					}
				}
				last = r;
			}
			n = last + 1;
			words.assign(n, 0);
			occurences.assign(n, 0);
			isTerminal.assign(n, false);

			int p = last;
			while(p >= 0){
				terminals.push_back(p);
				isTerminal[p] = true;
				p = link[p];
			}
			dfs(0);
		}
		void dfs(int u){
			if(occurences[u] > 0){
				return;
			}
			if(isTerminal[u]){
				++occurences[u];
				++words[u];
			}
			for(auto [ch, v] : edges[u]){
				dfs(v);
				occurences[u] += occurences[v];
				words[u] += words[v] + occurences[v];
			}
		}
		void order(int u, int k, string &ans){
			if(occurences[u] > k){
				return;
			}
			for(auto [ch, v] : edges[u]){
				if(words[v] >= k){
					ans.push_back(ch);
					k -= occurences[u];
					order(v, k, ans);
					break;
				}else{
					k -= words[v];
				}
			}
		}
		void dfs2(int u){
			for(auto [ch, v] : edges[u]){
				dfs2(v);
				words[u] += words[v] + 1;
				words[u] %= MOD;
			}
		}
		void order2(int u, int k, string &ans){
			if(k > words[u]){
				ans = "No such line";
			}
			if(k == 0){
				return;
			}
			for(auto [ch, v] : edges[u]){
				if(words[v] >= k - 1){
					ans.push_back(ch);
					--k;
					order2(v, k, ans);
					return;
				}else{
					k -= words[v];
				}
			}
		}
		string order(int k){
			string ans;
			order(0, k, ans);
			return ans;
		}
};
void solve(){
	string s;
	int k;
	cin >> s >> k;
	SuffixAutomaton sa(s);
	cout << sa.order(k) << '\n';
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
