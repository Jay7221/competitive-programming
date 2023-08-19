#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++)
		cin >> x[i];
	map<int, int> mp;
	int ans = 0, j = 0;
	for(int i = 0; i < n; i++){
		j = max(j, mp[x[i]]);
		ans = max(ans, i - j + 1);
		mp[x[i]] = i + 1;
	}
	cout << ans << '\n';
}