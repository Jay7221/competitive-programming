#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	multiset<int> A, B;
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		v[i] = {a, b};
		A.insert(a);
		B.insert(b);
	}
	int ans = INF;
	int maxA = 0, maxB = 0;
	sort(v.rbegin(), v.rend());
	for(auto [a, b] : v){
		B.erase(B.find(b));

		if(B.lower_bound(a) != B.end()){
			int bb = max(maxB, *B.lower_bound(a));
			ans = min(ans, bb - a);
		}

		B.insert(b);
		maxB = max(b, maxB);
	}
	for(int i = 0; i < n; ++i){
		int a, b;
		tie(a, b) = v[i];
		v[i] = {b, a};
	}
	sort(v.rbegin(), v.rend());
	for(auto [b, a] : v){
		A.erase(A.find(a));

		if(A.lower_bound(b) != A.end()){
			int aa = max(maxA, *A.lower_bound(b));
			ans = min(ans, aa - b);
		}

		A.insert(a);
		maxA = max(maxA, a);
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
