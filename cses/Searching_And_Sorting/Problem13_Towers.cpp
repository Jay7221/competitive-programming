#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++)
		cin >> x[i];
	vector<int> cur;
	cur.reserve(n);
	for(int i = 0; i < n; i++){
		auto k = upper_bound(cur.begin(), cur.end(), x[i]);
		if(k == cur.end())
			 cur.push_back(x[i]);
		else
			*k = x[i];
	}
	cout << cur.size() << '\n';
}