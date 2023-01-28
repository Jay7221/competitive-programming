#include<iostream>
using namespace std;
void solve(){
	int k, n;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	bool ans = false;
	bool tmp = true;
	for(int i = 0; i < n; ++i){
		if(a[i] != k)
			tmp = false;
	}
	ans = tmp;
	for(int i = 0; i < n - 1; ++i){
		if(a[i] == k){
			ans = true;
			break ;
		}
	}
	if(ans)
		cout << "Yes\n";
	else
		cout << "No\n";
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