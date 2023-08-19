#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
int ans, n;
vector<int> a;
void trim(){
	while(a.size() && a.back() <= 0)
		a.pop_back();
	n = a.size();
}
void proc(vector<int> &a){
	if(n == 0)
		return ;
	int last = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == a[0])
			last = i;
		else
			break ;
	}
	ans += 1;
	--a[last];
	for(auto &c : a)
		--c;
	trim();
	proc(a);
}
void solve(){
	cin >> n;
	a.clear();
	a.resize(n + 1);
	a[0] = 1;
	for(int i = 1; i < n; i++){
		int k;
		cin >> k;
		a[k]++;
	}
	sort(a.rbegin(), a.rend());
	trim();
	ans = n;
	for(int i = 0; i < n; i++){
		a[i] = a[i] - (n - i);
	}
	trim();
	proc(a);
	cout << ans << '\n';
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