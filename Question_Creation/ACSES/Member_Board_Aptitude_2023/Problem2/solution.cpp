#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	string s;
	for(int i = 0; i < n; ++i){
		s.push_back(a[i]);
		s.push_back(b[i]);
	}
	cout << s << '\n';
	return 0;
}
