#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	deque<int> cakes;
	for(int i = 0; i < n; i++){
		int d;
		cin >> d;
		cakes.push_back(d);
	}
	int ans = 0, mx = 0;
	while(!cakes.empty()){
		if(cakes.front() > cakes.back()){
			if(cakes.back() >= mx){
				ans++;
				mx = cakes.back();
			}
			cakes.pop_back();
		}else{
			if(cakes.front() >= mx){
				ans++;
				mx = cakes.front();
			}
			cakes.pop_front();
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
	for(int i = 1; i < t + 1; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}