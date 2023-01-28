#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	int sum = (n * (n + 1)) / 2;
	if(sum % (x + y)){
		cout << "IMPOSSIBLE\n";
		return ;
	}
	int req = x * (sum / (x + y));
	vector<int> ans;
	for(int i = n; i > 0; --i){
		if(req >= i){
			ans.push_back(i);
			req -= i;
		}
	}
	cout << "POSSIBLE\n";
	cout << ans.size() << '\n';
	for(auto c : ans){
		cout << c << ' ' ;
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i < t + 1; ++i){
		cout << "Case #" << i << ": " ;
		solve();
	}
}