#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define nll unsigned long long
nll L, R;
ll power(ll a, int p){
	ll ans = 1, rem = a;
	while(p > 0){
		if(p & 1){
			ans *= rem;
		}
		rem *= rem;
		p >>= 1;
	}
	return ans;
}
ll get(ll x, int l, int r){
	if(l == 0){
		int k = r - l + 1;
		stack<int> st;
		while(x > 0){
			st.push(x % k);
			x /= k;
		}
		while(st.size()){
			int d = st.top();
			st.pop();
			x = 10 * x + d;
		}	
		return x;
	}
	
	
	ll ans = 0;
	int k = r - l  + 1;
	for(ll p = 1; p <= x; p *= k){
		x -= p;
		ans = ans * 10 + l;
	}
	ll mlt = 1;
	while(x > 0){
		ans += mlt * (x % k);
		x /= k;
		mlt *= 10;
	}
	return ans;
}
nll get_min(int l, int r){
	ll mn = 0, mx = power(r - l + 1, 19) - 1;
	if(l > 0){
		for(int k = 0; k <= 18; ++k){
			mx += power(r - l + 1, k);
		}
	}
	while(mn < mx){
		ll mid = (mn + mx) / 2;
		if(get(mid, l, r) < L){
			mn = mid + 1;
		}else{
			mx = mid;
		}
	}
	return get(mn, l, r);
}
void solve(){
	cin >> L >> R;
	for(int k = 0; k < 10; ++k){
		for(int l = 0; l + k < 10; ++l){
			nll ans = get_min(l, l + k);
			if((ans >= L) && (ans <= R)){
				cout << ans << '\n';
				return;
			}
		}
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
