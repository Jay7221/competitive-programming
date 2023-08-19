#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	for(int i = 0; i < n; ++i){
		q[i] = i + 1;
	}
	for(int i = 0; i < n; ++i){
		cin >> p[i];
	}
	if(n == 1){
		cout << -1 << '\n';
		return ;
	}
	for(int i = 0; i < n - 1; ++i){
		if(p[i] == q[i]){
			swap(q[i], q[i + 1]);
		}
	}
	if(p[n - 1] == q[n - 1])
		swap(q[n - 1], q[n - 2]);
	for(auto c : q){
		cout << c << ' ';
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