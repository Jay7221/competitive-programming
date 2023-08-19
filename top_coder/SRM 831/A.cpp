#include<bits/stdc++.h>
using namespace std;
#define inf (int)(1e9 + 7)
#define debug(a) for(auto c : a){cerr << c << ' ';} cerr << '\n';
class SmallestOppositeNumber{
public:
	int construct(int X){
		set<int> s;
		for(int i = 0; i < 10; ++i){
			s.insert(i);
		}
		while(X){
			s.erase(X % 10);
			X /= 10;
		}
		int ans = 0;
		int k = 1;
		for(int i = 1; i < s.size(); ++i){
			k *= 10;
		}
		if(*s.begin() == 0){
			s.erase(0);
			if(s.size() == 0){
				return 0;
			}
			ans += (*s.begin()) * k;
			k /= 100;
			s.erase(s.begin());
		}
		for(auto c : s){
			ans += c * k;
			k /= 10;
		}
		return ans;
	}
};