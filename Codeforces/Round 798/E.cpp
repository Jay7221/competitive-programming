#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';}cerr << '\n';
class DSU{
public:
	vector<int> par;
	vector<int> sz;
	DSU(int n){
		par.resize(n);
		sz.resize(n);
		for(int i = 0; i < n; ++i){
			par[i] = i;
			sz[i] = 1;
		}
	}
	int find(int u){
		if(par[u] == u)
			return u;
		return par[u] = find(par[u]);
	}
	void merge(int a, int b){
		a = find(a);
		b = find(b);
		if(a == b)
			return ;
		if(sz[a] < sz[b])
			swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
	}
};
bool connected(vector<int>& a){
	int n = a.size();
	DSU data(32);
	int m = 0;
	set<int> s;
	for(int i = 0; i < n; ++i){
		if(a[i] == 0)
			return 0;
		int last = -1;
		for(int j = 0; j < 32; ++j){
			if(a[i] & (1 << j)){
				s.insert(j);
				if(last != -1)
					data.merge(last, j);
				last = j;
			}
		}
	}
	int prev = data.find(*s.begin());
	for(auto c : s){
		if(data.find(c) != prev)
			return 0;
	}
	return 1;
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int ans = 0;
	auto print_ans = [&](){
		cout << ans << '\n';
		for(int i = 0; i < n; ++i)
			cout << a[i] << ' ' ;
		cout << '\n';
	};

	for(int i = 0; i < n; ++i){
		if(a[i] == 0){
			++a[i];
			++ans;
		}
	}
	if(connected(a)){
		print_ans();
		return ;
	}
	for(int i = 0; i < n; ++i){
		++a[i];
		if(connected(a)){
			++ans;
			print_ans();
			return ;
		}
		--a[i];
		--a[i];
		if(connected(a)){
			++ans;
			print_ans();
			return;
		}
		++a[i];
	}
	int m = 0;
	for(int i = 0; i < n; ++i)
		m = max(m, a[i] & -a[i]);
	for(int i = 0; i < n; ++i){
		if((a[i] & -a[i]) == m){
			++ans;
			--a[i];
			break ;
		}
	}
	if(connected(a)){
		print_ans();
		return ;
	}
	for(int i = 0; i < n; ++i){
		if((a[i] & -a[i]) == m){
			++a[i];
			++ans;
			break ;
		}
	}
	print_ans();
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