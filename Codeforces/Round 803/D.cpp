#include<bits/stdc++.h>
using namespace std;
bool query(int l, int r){
	cout << "? " << l << ' ' << r << '\n';
	fflush(stdout);
	int cnt = 0;
	for(int i = 0; i < r - l + 1; ++i){
		int a;
		cin >> a;
		if((a >= l) && (a <= r)){
			++cnt;
		}
	}
	if(cnt % 2){
		return 1;
	}else{
		return 0;
	}
}
void solve(){
	int n;
	cin >> n;
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(query(l, mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << "! " << l << '\n';
	fflush(stdout);
	return ;
}
int main(){
	// freopen("inputf.in","r",stdin);
	// freopen("outputf.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}