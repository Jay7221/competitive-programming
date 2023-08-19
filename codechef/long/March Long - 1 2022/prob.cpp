#include<bits/stdc++.h>
using namespace std;
int main(){
	// int n;
	// cin>> n;
	// vector<int> a;
	// for(int i = 1; i <= n;i++){
	// 	int x;
	// 	cin >> x;
	// 	a.push_back(x);
	// }
	std::vector<int> v;
	int x;
	while(cin >> x){
		v.push_back(x);
	}
	for(auto c : v){
		cout << c << ' ';
	}
}
