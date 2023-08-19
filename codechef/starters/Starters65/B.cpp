#include<iostream>
using namespace std;
#define ll long long
const int maxK = 60;
void solve(){
	int n, q;
	cin >> n >> q;
	ll a[n + 1];
	a[0] = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int pre[n + 1][maxK][2] = {0};
	for(int k = 0; k < maxK; ++k){
		for(int i = 1; i <= n; ++i){
			if((a[i] >> k) & 1){
				pre[i][k][1] = 1;
			}else{
				pre[i][k][0] = 1;
			}
			pre[i][k][1] += pre[i - 1][k][1];
			pre[i][k][0] += pre[i - 1][k][0];
		}
	}
	auto query = [&](int L, int R, int k, int x){
		int ans = pre[R][k][x] - pre[L - 1][k][x];
		return ans;
	};
	while(q--){
		int k, L1, R1, L2, R2;
		cin >> k >> L1 >> R1 >> L2 >> R2;
		ll zeros1 = query(L1, R1, k, 0);
		ll zeros2 = query(L2, R2, k, 0);
		ll ones1 = query(L1, R1, k, 1);
		ll ones2 = query(L2, R2, k, 1);
		ll ans = ones1 * zeros2 + ones2 * zeros1;
		cout << ans << '\n';
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
	return 0;
}