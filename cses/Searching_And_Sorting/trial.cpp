#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n ;i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++)
		cin >> c[i];
	ll ans = accumulate(c.begin(), c.end(), 0ll);
	for(int i = 0; i < n; i++){
		a[i] = max(0, a[i] - c[i]);
		b[i] = max(0, b[i] - c[i]);
	}
	int k1, k2;
	cin >> k1 >> k2;
	set<pair<int, int> > p, q;
	for(int i = 0; i < n; i++){
		p.insert({a[i], i});
		q.insert({b[i], i});
	}
	stack<pair<int, int> > temp;
	set<pair<int, int> >::reverse_iterator it;
	for(it = q.rbegin(); it != q.rend() && k2; it++){
		int i = it -> second;
		if(b[i] > a[i]){
			k2--;
			ans += b[i];
			p.erase({a[i], i});
			temp.push({b[i], i});
		}
	}
	while(temp.size()){
		q.erase(temp.top());
		temp.pop();
	}
	for(it = p.rbegin(); it != p.rend() && k1--; it++){
		int i = it -> second;
		q.erase({b[i], i});
		ans += it -> first;
		temp.push(*it);
	}
	while(temp.size()){
		p.erase(temp.top());
		temp.pop();
	}
	for(it = q.rbegin(); it != q.rend() && k2--; it++){
		ans += it -> first;
	}
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