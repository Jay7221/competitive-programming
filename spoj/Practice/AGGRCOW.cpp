#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9 + 7;
void solve(){
	int n, c;
	cin >> n >> c;
	vector<int> x(n);
	for(int i = 0; i < n; ++i){
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	
	int l = 0, r = MAX;
	auto check = [&](int d){
		int prev = x[0];
		int cnt = 1;
		for(int elem: x){
			if(prev + d <= elem){
				prev = elem;
				++cnt;
			}
		}
		return (cnt >= c);
	};
	while(l < r){
		int mid = l + ((r - l + 1) >> 1);
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l << '\n';
}
int main() {
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
