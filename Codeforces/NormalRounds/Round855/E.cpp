#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<int> v){
	for(int elem : v){
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve(){
	int n, k;
	cin >> n >> k;
	vector<bool> vis(n);
	string s, t;
	cin >> s >> t;
	bool flag = true;

	auto check = [&](int u){
		return ((u >= 0) && (u < n) && (!vis[u]));
	};

	auto getCom = [&](int u){
		vector<int> com;
		queue<int> q;
		vis[u] = true;
		com.push_back(u);
		q.push(u);
		vector<int> d = {-k -1, -k, k, k + 1};
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int du : d){
				int uu = u + du;
				if(check(uu)){
					com.push_back(uu);
					q.push(uu);
					vis[uu] = true;
				}
			}
		}
		return com;
	};

	for(int i = 0; i < n; ++i){
		if(vis[i]){
			continue;
		}
		vector<int> component = getCom(i);
		vector<int> freq(26);
		for(int i : component){
			++freq[s[i] - 'a'];
			--freq[t[i] - 'a'];
		}
		for(int i = 0; i < 26; ++i){
			if(freq[i] != 0){
				flag = false;
			}
		}
	}
	if(flag){
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
