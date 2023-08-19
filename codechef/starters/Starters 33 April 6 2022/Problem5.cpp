#include<bits/stdc++.h>
using namespace std;
#define EPSILON 123
#define ll long long
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int mex = n;
	for(int i = 0; i < n; i++){
		if(a[i] != i){
			mex = i;
			break ;
		}
	}
	if(mex == 0){
		cout << a[0] - 1 << '\n';
		return ;
	}
	if(mex == 1){
		cout << -1 << '\n';
		return ;
	}
	int ans = 0;
	int i = 0;
	while(i < n){
		int consecutive = 1;
		while(i + 1 < n && a[i + 1] == a[i] + 1){
			i++;
			while(i + 1 < n && a[i + 1] == a[i])
				i++;
			consecutive++;
		}
		i++;
		while(i + 1 < n && a[i + 1] == a[i])
			i++;
		if(consecutive >= mex - 1)
			ans++;
	}
	cout << ans - 1 << '\n';

}
int main(){
	#ifdef EPSILON
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif
	int t;
	cin >> t;
	while(t--){
	solve();
	}
}