#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	deque<int> d;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		d.push_back(a);
	}
	int ans = 0;
	while(d.size() > 1){
		int af = d.front(), ab = d.back();
		d.pop_front();
		d.pop_back();
		++ans;
		if(af > ab){
			d.push_front(af - ab);
		}else if(af < ab){
			d.push_back(ab - af);
		}else{
			--ans;
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