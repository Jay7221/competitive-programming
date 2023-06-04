#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n, -1), b(n - 1);
	for(int i = 0; i < n - 1; ++i){
		cin >> b[i];
	}
	a[0] = b[0];
	for(int i = 1; i < n - 1; ++i){
		if(a[i] == -1){
			if(b[i] <= b[i - 1]){
				a[i] = b[i];
			}
		}
		if(a[i] < b[i]){
			a[i + 1] = b[i];
		}
	}
	for(int i = 0; i < n; ++i){
		if(a[i] == -1){
			a[i] = 0;
		}
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
