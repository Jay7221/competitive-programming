#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 7;
const int inf = 1e9 + 7;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> M(mx);
	// M[v] = maximum value of ( (a[i] / p) - v ), such that a[i] / p >= v over all i.
	for(int i = 0; i < n; ++i){
		int pv = inf;
		for(int j = 1; j < min(a[i], k) + 1; j = (a[i] / (a[i] / j)) + 1){
			int nv = a[i] / j;
			// nv = a[i] / j => a[i] / nv = j
			// and nv is the maximum integer satisfying this
			// M[nv + 1] = previous value of nv
			M[nv + 1] = max(M[nv + 1], pv);
			pv = nv;
		}
		M[0] = max(M[0], pv);
	}
	// Now if M[i] = k, then k - i = max(a[i] / p - i)
	// so M[i + 1] >= k, else if M[i + 1] < k, then for atleast one i, a[i] / p = k ans 
	// p is the maximum value satisfying this.
	for(int i = 1; i < a[0] + 1; ++i){
		M[i] = max(M[i], M[i - 1]);
	}
	int ans = inf;
	for(int i = 0; i < a[0] + 1; ++i){
		ans = min(ans, M[i] - i);
	}
	cout << ans << '\n';
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