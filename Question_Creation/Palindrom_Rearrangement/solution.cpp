#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int ans = 0;
	for(int i = 0; i < n; i += 2){
		ans += (abs(s[i] - s[i + 1]));
	}
	cout << ans << '\n';
}
int main()
{
	int T;
	T = 1;
	for(int t = 1; t <= T; ++t)
	{
		solve();
	}
	return 0;
}
