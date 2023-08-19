#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i <n; i++)
		cin >> a[i];
	int ans = n;
	sort(a.begin(), a.end());
	for(int i = 0; i < n - 1; i++){
		if(a[i] == a[i + 1])
			ans--;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}