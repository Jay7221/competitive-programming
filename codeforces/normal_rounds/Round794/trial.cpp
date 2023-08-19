#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define mx (int)(1e6 + 7)
vector<ll> factorial(mx), inverseFactorial(mx);
vector<ll> inverse(mx);
vector<set<vector<int> > > sets(7);
void brute(vector<int> cur){
	sort(cur.begin(), cur.end());
	int sum = accumulate(cur.begin(), cur.end(), 0);
	if(cur.size() == 7){
		if(sum % 7 == 0){
			sets[6].insert(cur);
		}
		return ;
	}
	if(sum % 7 && cur.size() > 0)
		sets[cur.size() - 1].insert(cur);
	for(int i = 0; i < 6; ++i){
		cur.push_back(i);
		brute(cur);
		cur.pop_back();
	}
}
void pre(){
	factorial[0] = 1;
	for(ll i = 1; i < mx; ++i)
		factorial[i] = (i * factorial[i - 1]) % mod;
	inverse[1] = 1;
	for(int i = 2; i < mx; ++i)
		inverse[i] = (inverse[mod % i] * (mod - mod / i)) % mod;
	inverseFactorial[0] = inverse[1];
	for(int i = 1; i < mx; ++i){
		inverseFactorial[i] = (inverseFactorial[i - 1] * inverse[i]) % mod;
	}
	vector<int> cur;
	brute(cur);
}
ll combination(int n, int k){
	if(k > n)
		return 0ll;
	ll ans = factorial[n];
	ans *= inverseFactorial[k];
	ans %= mod;
	ans *= inverseFactorial[n - k];
	ans %= mod;
	return ans;
}
void solve(){
	int n;
	cin >> n;
	vector<int> freq(7);
	for(int i = 0; i < n; ++i){
		int a; 
		cin >> a;
		++freq[a % 7];
	}
	vector<int> ansOfK(7);
	int q;
	cin >> q;
	auto compute = [&](int k){
		if(k >= 7){
			ll ans = 0;
			for(int i = 1; i < 7; ++i){
				ans += combination(freq[i], k);
				ans %= mod;
			}
			return ans;
		}else{
			return 0ll;
		}

	};
	while(q--){
		int k ;
		cin >> k;
		cout << compute(k) << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	pre();
	while(t--){
		solve();
	}
}