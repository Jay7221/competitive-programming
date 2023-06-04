#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	auto check = [&](int d){
		int cur = 1;
		int prev = a[0];
		for(int i = 0; i < n; ++i){
			if(a[i] >= prev + d){
				++cur;
				prev = a[i];
			}
		}
		return (cur >= k);
	};
	int l = 0, r = 1e9 + 7;
	while(l < r){
		int m = (l + r + 1) / 2;
		if(check(m)){
			l = m;
		}else{
			r = m - 1;
		}
	}
	cout << l << '\n';
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
