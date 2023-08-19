#include<bits/stdc++.h>
using namespace std;
void print(vector<int> &v){
	for(int elem : v){
		cerr << elem << ' ';
	}
	cerr << '\n';
}
void solve(){
	const int INF = 1e9 + 7;
	const int MAX = 1e6 + 7;
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	auto check = [&](int m){
		vector<int> v = a;
		for(int i = 0; i < n; ++i){
			v[i] = (((v[i] % m) + m) % m);
		}
		sort(v.begin(), v.end());
		for(int l = 0, r = (n - 1) / 2; r < n; ++l, ++r){
			if(v[l] == v[r]){
				return true;
			}
		}
		return false;
	};
	set<int> st;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			int diff = abs(a[i] - a[j]);
			for(int d = 1; d * d <= diff; ++d){
				if(diff % d == 0){
					st.insert(d);
					if(d * d != diff){
						st.insert(diff / d);
					}
				}
			}
		}
	}
	int ans;
	for(int i : st){
		if(check(i)){
			ans = i;
		}
	}
	if(check(INF)){
		ans = -1;
	}
	cout << ans << '\n';
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