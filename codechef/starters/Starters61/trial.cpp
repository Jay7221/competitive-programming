#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<pair<int, pair<int, int> > > d = {{1, {2, 3}}};
	for(auto [a, b] : d){
		cerr << a<< ' '  << '\n';
	}
}
