#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
	int a1, b1, a2, b2;
	tie(a1, b1) = a;
	tie(a2, b2) = b;
	int k1 = min(-a1, b1 - (a1 + a2));
	int k2 = min(-a2, b2 - (a1 + a2));
	return (k1 > k2);
}
void solve(){
	int n;
	cin >> n;
	long long a[n];
	long long b[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	long long H;
	cin >> H;
	vector<pair<long long, long long>> good, bad;
	for(int i = 0; i < n; ++i){
		if(a[i] >= b[i])
			good.push_back({a[i], b[i]});
		else
			bad.push_back({a[i], b[i]});
	}
	sort(good.begin(), good.end());
	sort(bad.begin(), bad.end());
	bool flag = true;
	long long cur = H;
	for(auto [x, y] : good){
		if(cur < x){
			flag = false;
			break ;
		}else{
			cur += y - x;
		}
	}
	for(auto [x, y] : bad){
		if(cur < x){
			flag = false;
			break ;
		}else{
			cur += y - x;
		}
	}
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
int main(int argc, char **argv){
	if(argc > 1){
		freopen(argv[1], "r", stdin);
		freopen("solution.txt", "w", stdout);
	}
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
};
