#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
template<typename T>
void debug(vector<T> &v){
	for(T elem : v){
		cout << elem << ' ' ;
	}
	cout << '\n';
}
void solve(){
	int n, q;
	cin >> n >> q;
	vector<ll> a(n), query(q);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(ll &k : query){
		cin >> k;
	}
	sort(a.begin(), a.end());
	vector<ll> b, preMin, noOperations(n);
	b = a;
	for(int i = 0; i < n; ++i){
		b[i] -= i;
	}
	preMin = b;
	for(int i = 1; i < n; ++i){
		preMin[i] = min(preMin[i], preMin[i - 1]);
	}
	for(int i = 1; i < n; ++i){
		if(preMin[i] < preMin[i - 1]){
			noOperations[i] = noOperations[i - 1] + i * (preMin[i - 1] - preMin[i]) + (b[i] - preMin[i]);
		}else{
			noOperations[i] = noOperations[i - 1] + (b[i] - preMin[i]);
		}
	}
	// debug(a);
	// debug(b);
	// debug(preMin);
	// debug(noOperations);
	auto get = [&](ll k){
		if(n == 1){
			ll ans = a[0];
			if(k % 2 == 1){
				ans += (1 + k) / 2;
			}else{
				ans -= k / 2;
			}
			return ans;
		}
		
		bool flag = ((n % 2) != (k % 2));
		
		if(flag){
			--n;
		}
		
		ll ans;
		if(k < n){
			ans = preMin[k - 1] + k;
			ans = min(ans, a[k]);
			k = 0;
		}else{
			ans = preMin[n - 1] + k;
			k -= n;
			k /= 2;
			k -= noOperations[n - 1];
			if(flag){
				ll x = a.back();
				if(x <= ans){
					k -= n * (ans - x);
					ans = x;
				}else{
					k -= (x - ans);
				}
			}
		}
		if(flag){
			++n;
		}
		if(k > 0){
			ans -= (k + n - 1) / n;
		}
		return ans;
	};
	for(int k : query){
		cout << get(k) << ' ';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
	
	return 0;
}