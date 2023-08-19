#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    if(n == 1){
        ans = a[1];
    }else if(n == 2){
        ans = max(a[1] + a[2], 2 * abs(a[1] - a[2]));
    }else if(n == 3){
        ans = a[1] + a[2] + a[3];
        ans = max(ans, 3 * a[1]);
        ans = max(ans, 3 * a[3]);
        ans = max(ans, 3 * max(abs(a[1] - a[2]), abs(a[2] - a[3])));
        ans = max(ans, a[1] + 2 * abs(a[2] - a[3]));
        ans = max(ans, 2 * abs(a[1] - a[2]) + a[3]);
    }else{
        ans = n * (*max_element(a.begin(), a.end()));
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
