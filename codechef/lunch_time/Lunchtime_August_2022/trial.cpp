#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int, int> m;
	m[0] = 1;
	m[1] = 2;
	for(auto c : m){
		cerr << c.first << ' ' << c.second << '\n';
	}
}