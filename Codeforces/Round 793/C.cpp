#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	set<int> p, q;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		if(p.find(a) == p.end())
			p.insert(a);
		else
			q.insert(a);
	}
	if(p.size() == q.size()){
		cout << p.size() << '\n';
		return ;
	}
	int ans = p.size();
	ans -= (p.size() - q.size()) / 2;
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