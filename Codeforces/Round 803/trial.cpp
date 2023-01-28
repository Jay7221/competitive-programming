#include<bits/stdc++.h>
using namespace std;
#define prep(a) a.clear();	a.resize(n + 1);
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
vector<int> a, pre;
int n;
int get_min(int x){
	map<int, int> m;
	int ans = n + 1;
	for(int i = 1; i < n + 1; ++i){
		if(pre[i] == x){
			ans = min(ans, i);
		}
		if(m[pre[i] ^ x] != 0){
			ans = min(ans, i - m[a[i] ^ x]);
		}
		m[pre[i]] = i;
	}
	return ans;
}
void solve(){
	cin >> n;
	int k ;
	cin >> k;
	prep(a)
	prep(pre)
	for(int i = 1; i < n + 1; ++i){
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}
	int ans = get_min(k);
	for(int i = 30; i > -1; --i){
		if(k & (1 << i))
			continue;
		int k1 = (k | (1 << i));
		k1 = ((k1 >> i) << i);
		for(int j = 1; j < n + 1; ++j){
			pre[j] = pre[j - 1] ^ ((a[j] >> i) << i);
		}
		ans = min(ans, get_min(k1));
	}
	if(ans != n + 1){
		cout << ans << '\n';
	}else{
		cout << -1 << '\n';
	}
}
int main(){
	freopen("inputf.in","r",stdin);
	freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}