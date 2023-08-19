#include<bits/stdc++.h>
using namespace std;
int k;
void proc(vector<int> &a, int l, int r){
	if(l == r)
		return ;
	int mid = (l + r) / 2;
	proc(a, l, mid);
	proc(a, mid + 1, r);
	if(a[l] > a[mid + 1]){
		++k;
		for(int i = 0; i <= mid - l; ++i){
			swap(a[l + i], a[mid + 1 + i]);
		}
	}
}
void solve(){
	int m;
	cin >> m;
	vector<int> a(m + 1);
	for(int i = 1; i <= m; ++i)
		cin >> a[i];
	vector<int> b = a;
	sort(b.begin(), b.end());
	k = 0;
	proc(a, 1, m);
	if(a == b){
		cout << k << '\n';
	}else{
		cout << -1 << '\n';
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