#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	if(n % 2){
		if(n < 5){
			cout << -1 << '\n';
			return ;
		}
		vector<int> ans(n);
		for(int i = n - 5; i < n; i++)
			ans[i] = i + 1;
		for(int i = 0; i < n - 5; i += 2){
			ans[i] = i + 2;
			ans[i + 1] = i + 1;
		}
		int a[5];
		a[0] = ans[n - 5];
		a[1] = ans[n - 4];
		a[2] = ans[n - 3];
		a[3] = ans[n - 2];
		a[4] = ans[n - 1];
		ans[n - 1] = a[3];
		ans[n - 2] = a[0];
		ans[n - 3] = a[4];
		ans[n - 4] = a[2];
		ans[n - 5] = a[1];
		for(auto c : ans)
			cout << c << ' ' ;
		cout << '\n';
	}
	else{
		for(int i = 0; i < n; i++)
			cout << n - i << ' ' ;
		cout << '\n';
	}
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