#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > p(n + 2);
	vector<int> x(n + 1);
	x[0] = 0;
	p[0] = {0, 0}, p[n + 1] = {n + 1, n + 1};
	for(int i = 1; i < n + 1; i++){
		int a;
		cin >> a;
		x[i] = a;
		p[i] = {a, i};
	}
	sort(p.begin(), p.end());
	int ans = 1;
	for(int i = 1; i < n + 1; i++){
		if(p[i].second < p[i - 1].second)
			ans++;
	}
	while(m--){
		int a, b;
		cin >> a >> b;
		int i = a, j = b;
		a = x[a], b = x[b];
		swap(x[i], x[j]);
		if(a > b)
			swap(a, b);
		ans -= (p[a].second > p[a + 1].second) + (p[a].second < p[a - 1].second);
		ans -= (p[b].second > p[b + 1].second) + (p[b].second < p[b - 1].second);
		if(a + 1 == b){
			ans += p[a].second > p[a + 1].second;
		}
		swap(p[a].second, p[b].second);
		ans += (p[a].second > p[a + 1].second) + (p[a].second < p[a - 1].second);
		ans += (p[b].second > p[b + 1].second) + (p[b].second < p[b - 1].second);
		if(a + 1 == b){
			ans -= p[a].second > p[a + 1].second;
		}
		cout << ans << '\n';
	}
}