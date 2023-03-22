#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	priority_queue<int> pq;
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] > 0){
			pq.push(s[i]);
		}
		else{
			if(pq.size()){
				ans += pq.top();
				pq.pop();
			}
		}
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

	return 0;
}
