#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0; i < n ;i++){
		cin >> a[i];
	}
	priority_queue<ll> cons;
	for(int i = 0; i < n; i++){
		ll consecutive = 1;
		while(i + 1 < n && a[i] == a[i + 1]){
			i++;
			consecutive++;
		}
		cons.push(consecutive);
	}
	ll ans = 0;
	while(k-- && !cons.empty()){
		ll temp = cons.top();
		cons.pop();
		ans += 1;
		switch(temp){
			case 1:
				break ;
			case 2:
				ans += 1;
				break ;
			case 3: 
				ans += 2;
				break ;
			case 4:
				ans += 2;
				cons.push(2);
			default:
				cons.push(temp / 2);
				cons.push((temp - 1) / 2);
				break ;
		}
	}
	while(!cons.empty()){
		int temp = cons.top();
		cons.pop();
		ans += (temp * (temp + 1)) / 2;
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