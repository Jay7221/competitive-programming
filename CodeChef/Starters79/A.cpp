#include<bits/stdc++.h>
using namespace std;
void solve(){
	int N;
	cin >> N;
	int n = N / 2;
	vector<int> arr(N + 1);
	for(int i = 1; i <= n; ++i){
		arr[i] = i;
	}
	for(int i = n + 1; i <= N; ++i){
		arr[i] = 3 * n + 1 - i;
	}
	for(int i = 1; i <= N; ++i){
		cout << arr[i] << ' ';
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
