#include<bits/stdc++.h>
using namespace std;
#define debug(a) for(auto c : a){cerr << c << ' ' ;} cerr << '\n';
int main(){
	int x, n;
	cin >> x >> n;
	set<int> s;
	// s stores all the positions for which the traffic lights are lit
	multiset<int> m;
	// m stores the lengths of the series of passages without any traffic light
	s.insert(0);
	s.insert(x);
	m.insert(x);
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		auto it = s.upper_bound(p);
		auto it2 = it;
		it--;
		m.erase(m.find(*it2 - *it));
		s.insert(p);
		m.insert(*it2 - p);
		m.insert(p - *it);
		cout << *(--m.end()) << ' ' ;
	}
}