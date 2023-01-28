#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e15 + 7;
const ll MOD = 1e9 + 7;
void solve(){
	auto gcd = [&](int a, int b){
		while(b){
			int tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
	};
	int n;
	cin >> n;
	// suppose that we change a[i] to a[i] + 1
	// now if gcd(a[i], a[i + 1]) > 1 and gcd(a[i] + 1, a[i + 1]) > 1 that implies that a[i + 1] has atleast two distinct prime factors
	// now considering the first four primes 2, 3, 5, 7, 11, 13, 17, their product is 510510
	// that is for any a[i], has at most 6 distinct prime factors

	// now gcd(a[i], a[i + 1]) > 1 and gcd(a[i] + 1, a[i + 1]) > 1 implies that a[i + 1] has atleast distinct two prime factors, as gcd(a[i], a[i] + 1) = 1 and a[i], a[i] + 1 do not share any commone factor
	// also the cost of changing a[i] is 2 ^ (abs(a[i] - b[i])), thus it is reasonable to change a[i] in the range abs(a[i] - b[i]) <= 10

	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	// dp[i][k] = the cost of changing a[i] to b[i] = a[i] + (k - 10);
	// k - 10 is used to ensure that b[i] <= a[i] and b[i] > a[i] both cases are considered

	vector<vector<ll> > dp(n, vector<ll>(21, INF));
	for(int i = 0; i < 21; ++i){
		dp[0][i] = (1ll << abs(i - 10));
		dp[0][i] %= MOD;
	}
	for(int i = 1; i < n; ++i){
		for(int k = 0; k < 21; ++k){
			for(int j = 0; j < 21; ++j){
				b[i] = a[i] + (k - 10), b[i - 1] = a[i - 1] + (j - 10);
				if(gcd(b[i], b[i - 1]) > 1 || min(b[i], b[i - 1]) < 0){
					continue ;
					// as by the constraints given in the question gcd(b[i], b[i + 1]) = 1
					// and b[i] >= 0
				}
				else{
					dp[i][k] = min(dp[i][k], (dp[i - 1][j] + (1ll << (abs(k - 10)) ) % MOD ) % MOD);
				}
			}
		}
	}
	cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
	// now answer is simply the minimum cost for any one of the possible last elements
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}