#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	set<int> heads;
	heads.insert(0);
	int cur = a[0];
	for(int i = 1; i < n; ++i){
		if(a[i] < cur){
			heads.insert(i);
			cur = a[i];
		}
	}
	while(m--){
		int k, d;
		cin >> k >> d;
		--k;
		a[k] -= d;
		auto it = heads.upper_bound(k);
		while(it != heads.end() && a[*it] >= a[k]){
			heads.erase(it++);
		}
		--it;
		if(a[k] < a[*it])
			heads.insert(k);
		cout << heads.size() << ' ';
	}
	cout << '\n';
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