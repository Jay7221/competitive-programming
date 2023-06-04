#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> L(n), R(n);
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> L[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> R[i];
	}
	ll ans = INF;
	int s = 0, c = 0;
	for(int i = 0; i < n; ++i){
		int l = L[i], r = R[i];
		if(r - l + 1 == 1){
			++c;
		}else{
			s += r - l + 1;
		}
		if(s + c >= k){
			if(s >= k){
				ans = min(ans, (r - (s - k)) + 2ll * (i - c + 1));
			}else{
				ans = min(ans, r + 2ll * ((i - c + 1) + (k - s)));
			}
		}
	}
	if(ans == INF){
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
