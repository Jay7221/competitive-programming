#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> b = a;
	sort(b.begin(), b.end());
	int z = b[n - 2] + b[n - 1];
	int cur = 0;
	for(int i = 1; i < n; i += 2){
		a[i] = b[cur];
		++cur;
	}
	cur = n - 1;
	for(int i = 0; i < n; i += 2){
		a[i] = b[cur];
		--cur;
	}
	for(int i = 1; i < n; ++i){
		if((a[i] + a[i - 1]) >= z){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		solve();
	}
}
