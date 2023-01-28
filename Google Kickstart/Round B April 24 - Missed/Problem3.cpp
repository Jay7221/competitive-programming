#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define inf (int)(1e9 + 7)
void solve(){
	int n, d;
	cin >> n >> d;
	vector<int> val(n);
	for(int i = 0; i < n; i++)
		cin >> val[i];
	auto cost = [&](int a){
		int i = a - 1, j = a + 1;
		int cur = val[a];
		int ans = 0;
		while(i > -1 || j < n){
			if(j > n - 1){
				cur = val[i];
				ans += min(abs(val[i] - cur), d - abs(val[i] - cur));
				i--;
			}
			else if(i < 0){
				cur = val[j];
				ans += min(abs(val[j] - cur), d - abs(val[j] - cur));
				j++;
			}
			else{
				int k_1 = min(abs(val[i] - cur), d - abs(val[i] - cur)), k_2 = min(abs(val[j] - cur), d - abs(val[j] - cur));
				if(k_1 < k_2){
					cur = val[i];
					ans += k_1;
					i--;
				}else{
					cur = val[j];
					ans += k_2;
					j++;
				}
			}
		}
		return ans;
	};
	int ans = (int)(1e9 + 7);
	for(int i = 0; i < n; i++){
		cerr << i << ' ' << cost(i) << '\n';
		ans = min(ans, cost(i));
	}
	cerr << '\n';
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}