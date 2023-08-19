#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> L(n + 2), R(n + 2, n), l(n + 2), r(n + 2, n);
	for(int i = 1; i <= n; ++i){
		cin >> L[i] >> R[i];
	}
	vector<int> preL(n + 2, 0), sufL(n + 2, 0), preR(n + 2, n), sufR(n + 2, n);
	for(int i = 1; i < n + 1; ++i){
		preL[i] = max(preL[i - 1], L[i]);
		preR[i] = min(preR[i - 1], R[i]);
	}	
	for(int i = n; i > 0; --i){
		sufL[i] = max(sufL[i + 1], L[i]);
		sufR[i] = min(sufR[i + 1], R[i]);
	}
	for(int i = 1; i < n + 1; ++i){
		l[i] = max(preL[i - 1], sufL[i + 1]);
		r[i] = min(preR[i - 1], sufR[i + 1]);
	}
	vector<int> ans;
	for(int i = 1; i < n + 1; ++i){
		if((i >= l[i]) && (i <= r[i]) && !( (i <= R[i]) && (i >= L[i]) )){
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for(auto c : ans){
		cout << c << '\n';
	}
}
int main(){
	// freopen("inputf.in","r",stdin);
	// freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}