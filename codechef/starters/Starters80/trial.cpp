#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll a = 125000015;
	ll b = 4;
	ll mod = 1e9 + 7;
	for(ll b = 2; b < 100; ++b){
		cout << b << " : ";
		cout << ((a * b) % mod) << '\n';
	}
	return 0;
}
