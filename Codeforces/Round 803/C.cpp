#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if(n < 7){
		for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; ++j){
				for(int k = j + 1; k < n; ++k){
					ll sum = a[i] + a[j] + a[k];
					bool flag = 0;
					for(int p = 0; p < n; ++p){
						if(sum == a[p]){
							flag = 1;
							break ;
						}
					}
					if(!flag){
						cout << "NO\n";
						return ;
					}
				}
			}
		}
		cout << "YES\n";
		return ;
	}
	for(int i = 1; i < n - 1; ++i){
		if(a[i] != 0){
			cout << "NO\n";
			return ;
		}
	}
	ll sum = a[0] + a[n - 1];
	for(int i = 0; i < n; ++i){
		if(a[i] == sum){
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
	return ;
}
int main(){
	// freopen("inputf.in","r",stdin);
	// freopen("outputf.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}