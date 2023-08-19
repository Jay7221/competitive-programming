#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> permutation(n + 1);
	int cur = n;
	for(int i = 1; i <= n; i += 2){
		permutation[i] = cur--;
	}
	cur = 1;
	for(int i = 2; i <= n; i += 2){
		permutation[i] = cur++;
	}
	for(int i = 1; i <= n; ++i){
		cout << permutation[i] << ' ';
	}
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