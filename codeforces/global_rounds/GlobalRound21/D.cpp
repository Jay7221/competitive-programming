#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c: a){cerr <<  c << ' ' ;} cerr << '\n';
void solve(){
	int n;
	cin >> n;
	vector<int> pos(n + 1), premx(n + 1), premn(n + 1), sufmx(n + 1), sufmn(n + 1), a(n + 1);
	for(int i = 1; i < n + 1; ++i){
		cin >> a[i];
		pos[a[i]] = i;
	}
	premx[1] = premn[1] = 1;
	for(int i = 2; i < n + 1; ++i){
		premx[i] = premx[i - 1];
		premn[i] = premn[i - 1];
		if(a[i - 1] > a[premx[i]]){
			premx[i] = i - 1;
		}
		if(a[i - 1] < a[premn[i]]){
			premn[i] = i - 1;
		}
	}
	sufmx[n] = sufmn[n] = n;
	for(int i = n - 1; i > 0; --i){
		sufmx[i] = sufmx[i + 1];
		sufmn[i] = sufmn[i + 1];
		if(a[i + 1] > a[sufmx[i]]){
			sufmx[i] = i + 1;
		}
		if(a[i + 1] < a[sufmn[i]]){
			sufmn[i] = i + 1;
		}
	}
	int ans = 0;
	int k = pos[1];
	bool last = 0;
	while(k != 1){
		if(last == 0){
			k = premx[k];
		}else{
			k = premn[k];
		}
		++ans;
		last ^= 1;
	}
	k = pos[1];
	last = 0;
	while(k != n){
		if(last == 0){
			k = sufmx[k];
		}else{
			k = sufmn[k];
		}
		++ans;
		last ^= 1;
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