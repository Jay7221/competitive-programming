#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5;
const int maxM = 1e5;
const int maxA = 1e9;
const int maxT = 100;
void generate_testcase(){
	int n = (rand() % maxN) + 1;
	int m = (rand() % maxM) + 1;
	m = min(m, n * (n - 1) / 2);
	assert((n >= 1) && (n <= maxN));
	assert((m >= 0) && (m <= min(maxM, n * (n - 1) / 2)));
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		a[i] = (rand() % maxA) + 1;
		assert((a[i] >= 1) && (a[i] < maxA));
	}
	set<pair<int, int> > edges;
	if(m == n * (n - 1) / 2){
		for(int i = 1; i <= n; ++i){
			for(int j = i + 1; j <= n; ++j){
				edges.insert({i, j});
			}
		}
	}else{
	}
	cout << n << ' ' << m << '\n';
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ' ;
	cout << '\n';
	for(auto [u, v] : edges)
		cout << u << ' ' << v << '\n';
}
int main(){
	srand(time(0));
	int t = (rand() % maxT) + 1;
	assert((t >= 1) && (t <= maxT));
	while(t--){
		generate_testcase();
	}
	return 0;
}	
