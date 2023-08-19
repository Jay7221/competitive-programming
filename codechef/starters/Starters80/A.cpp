#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	if(n % 2 == 1){
		cout << -1 << '\n';
		return ;
	}
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		a[i] = i + 1;
	}
	for(int i = 0; i + 1 < n; i += 2){
		swap(a[i], a[i + 1]);
	}
	for(int i = 0; i < n; ++i){
		cout << a[i] << ' ';
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

	return 0;
}
