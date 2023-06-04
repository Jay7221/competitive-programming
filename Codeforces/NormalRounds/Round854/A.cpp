#include<bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<int> &v){
	for(int elem : v){
		cout << elem << ' ';
	}
	cout << '\n';
}
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> t(n, -1);
	vector<int> p(m);
	vector<bool> vis(m);
	for(int i = 0; i < m; ++i){
		cin >> p[i];
		p[i] -= n + 1;
	}
	int cur = n - 1;
	for(int i = 0; (i < m) && (cur > -1); ++i){
		if(!vis[p[i]]){
			vis[p[i]] = true;
			t[cur] = i + 1;
			--cur;
		}
	}
	print(t);
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
