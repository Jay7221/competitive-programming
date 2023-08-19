#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
#define mx (int)(500 * 500 + 1000)
#define print(a) for(auto c : a){cout << c << ' ' ;} cout << '\n';
void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n + 2);
	for(ll i = 1; i < n + 1; ++i)
		cin >> a[i];
	vector<vector<bool> > pre(n + 2, vector<bool>(mx)), suf(n + 2, vector<bool>(mx)), last_pre(n + 2, vector<bool>(mx)) , last_suf(n + 2, vector<bool>(mx));
	pre[0][0] = 1, suf[n + 1][0] = 1;
	ll sumi = 0;
	for(ll i = 1; i < n + 1; ++i){
		for(ll j = sumi; j >= 0; --j){
			pre[i][j] = pre[i - 1][j];
			if(!pre[i - 1][j])
				continue ;
			if(pre[i][j + a[i]])
				continue;
			pre[i][j + a[i]] = 1;
			last_pre[i][j + a[i]] = 1;
		}
		sumi += a[i];
	}
	sumi = 0;
	for(ll i = n; i >= 0; --i){
		for(ll j = sumi; j >= 0; --j){
			suf[i][j] = suf[i + 1][j];
			if(!suf[i + 1][j])
				continue ;
			if(suf[i][j + a[i]])
				continue;
			suf[i][j + a[i]] = 1;
			last_suf[i][j + a[i]] = 1;
		}
		sumi += a[i];
	}
	ll tot = accumulate(a.begin(), a.end(), 0ll);
	auto getans = [&](int ind){
		ll req = (tot - a[ind]) / 2;
		ll j = req;
		ll k = 0;
		for(ll i = 0; i < req + 1; ++i){
			if(!pre[ind - 1][i])
				continue;
			while(i + j > req)
				--j;
			while(j > 0 && !suf[ind + 1][j])
				--j;
			if(pre[ind - 1][i] && pre[ind + 1][j]){
				k = max(k, i + j);
			}
		}
		k += a[ind];
		return k;
	};
	ll ind = 1, ans = getans(1);
	for(ll i = 1; i < n + 1; ++i){
		ll tmp = getans(i);
		if(tmp > ans){
			ans = tmp;
			ind = i;
		}
	}
	auto construct = [&](ll ind){
		ll req = (tot - a[ind]) / 2;
		ll tmp = 0;
		ll j = req;
		ll x, y;
		for(ll i = 0; i < req + 1; ++i){
			if(!pre[ind - 1][i])
				continue ;
			while(i + j > req)
				--j;
			while(j > 0 && !suf[ind + 1][j])
				--j;
			if(i + j > tmp){
				tmp = i + j;
				x = i, y = j;
			}
		}
		vector<ll> A, B;
		A.push_back(ind);
		for(ll i = ind - 1; i > 0; --i){
			if(last_pre[i][x]){
				A.push_back(i);
				x -= a[i];
			}
		}
		for(ll i = ind + 1; i < n + 1; ++i){
			if(last_suf[i][y]){
				A.push_back(i);
				y -= a[i];
			}
		}
		vector<bool> ok(n + 2, 1);
		for(auto c : A)
			ok[c] = 0;
		for(ll i = 1; i < n + 1; ++i){
			if(ok[i])
				B.push_back(i);
		}
		vector<ll> C;
		ll sum1 = 0, sum2 = 0;
		while(sum1 + sum2 < tot){
			if(sum1 <= sum2){
				ll ind = A.back();
				A.pop_back();
				sum1 += a[ind];
				C.push_back(ind);
			}else{
				ll ind = B.back();
				B.pop_back();
				sum2 += a[ind];
				C.push_back(ind);
			}
		}
		print(C)
	};
	construct(ind);
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
}