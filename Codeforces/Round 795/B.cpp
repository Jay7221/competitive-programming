#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), p(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		p[i] = i;
	}
	bool flag = 1;
	for(int i = 0; i < n; ++i){
		int j = i;
		while(j + 1 < n && a[j] == a[j + 1])
			++j;
		if(j == i){
			flag = 0;
			break ;
		}
		int nn = j - i + 1;
		for(int k = 0; k < nn; ++k){
			p[k + i] = i + ((k + 1) % nn);
		}
		i = j;
	}
	if(!flag){
		cout << -1 << '\n';
	}else{
		for(auto c : p)
			cout << c + 1 << ' ' ;
		cout << '\n';
	}
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