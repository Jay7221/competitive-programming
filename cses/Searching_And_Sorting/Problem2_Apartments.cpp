#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0;
	int ans = 0;
	debug(a)
	debug(b)
	while(i < n && j < m){
		if(abs(a[i] - b[j]) <= k){
			i++;
			j++;
			ans++;
		}
		else if(a[i] < b[j]){
			i++;
		}else{
			j++;
		}
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}