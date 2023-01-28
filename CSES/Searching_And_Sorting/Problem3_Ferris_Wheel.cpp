#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> w(n);
	for(int i = 0; i < n; i++)
		cin >> w[i];
	int sum = 0, ans = 0;
	sort(w.begin(), w.end());
	int i = 0, j = n - 1;
	while(i < j){
		while(i < j && w[i] + w[j] > x){
			ans++;
			j--;
		}
		if(i < j && w[i] + w[j] <= x){
			i++;
			j--;
			ans++;
		}
		if(i == j){
			ans++;
		}
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}