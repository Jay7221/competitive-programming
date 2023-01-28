#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > p(n);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		p[i] = {a, i};
	}
	sort(p.begin(), p.end());
	int ans = 1;
	for(int i = 1; i < n; i++){
		if(p[i].second < p[i - 1].second)
			ans++;
	}
	cout << ans << '\n';
}