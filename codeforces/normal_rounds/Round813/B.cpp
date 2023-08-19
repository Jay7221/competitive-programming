#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 1; i <= n; ++i)
		v[i - 1] = i;
	for(int i = n % 2; i + 1 < n; i += 2)
		swap(v[i], v[i + 1]);
	for(auto c : v)
		cout << c << ' ';
	cout << '\n';
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
}