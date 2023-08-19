#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
vector<int> dist(10000);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i = 0; i < 1000; ++i)
		dist[i] = -i;
	auto cmp = [&](int a, int b){
		return dist[a] < dist[b];
	};
	set<int, decltype(cmp)> s(cmp);
	s.insert(1);
	s.insert(2);
	for(int i = 0; i < 100; ++i)
		s.insert(i);
	for(auto c : s)
		cerr << c << ' ';
	cerr <<  '\n';
}