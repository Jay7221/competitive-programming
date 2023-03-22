#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin >> n;
	ll a = 0, b = 0, c = 0, d = 0;
	bool flag = true;
	auto apply = [&](ll &n, int k){
		n |= (1ll << k);
		return n;
	};
	int cnt1 = 0, cnt2 = 0;
	for(int k = 0; k < 32; ++k){
		int nk = (1ll & (n >> k));
		if(nk == 0){
			if(cnt2 == 0){
				apply(a, k);
			}else if(cnt2 == 1){
				apply(b, k);
			}else if(cnt2 == 2){
				apply(a, k);
				apply(b, k);
				apply(d, k);
			}else{
				apply(c, k);
				apply(d, k);
			}
			++cnt2;
			cnt2 %= 4;
		}else{
			if(cnt1 == 0){
				apply(c, k);
			}else if(cnt1 == 1){
				apply(b, k);
				apply(d, k);
			}else{
				apply(a, k);
				apply(d, k);
			}
			++cnt1;
			cnt1 %= 4;
		}
	}
	// cerr << (((a & b) | c) ^ d) << '\n';
	cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
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
