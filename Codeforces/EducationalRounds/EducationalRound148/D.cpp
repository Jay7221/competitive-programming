#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
void solve(){
	int n, q;
	cin >> n >> q;
	vector<ll> a(n), query(q);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int j = 0; j < q; ++j){
		cin >> query[j];
	}
	auto get = [&](ll k){
		vector<ll> v = a;
		bool flag = ((n % 2) != (k % 2));
		ll ans = 0;
		if(flag){
			--n;
		}
		for(int i = 0; i < n; ++i){
			if(k < i){
				break;
			}
			v[i] += k - i;
		}
		k -= n;
		k /= 2;
		sort(v.begin(), v.end());
		for(int i = 1; i < v.size(); ++i){
			ll tmp = min(v[i] - v[0], k);
			v[i] -= tmp;
			k -= tmp;
		}
		ans = v[0];
		if(flag){
			++n;
		}
		ans -= (k + n - 1) / n;
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