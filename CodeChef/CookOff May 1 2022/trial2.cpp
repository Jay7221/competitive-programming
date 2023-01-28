#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin >> n;
	auto f = [&](ll i){
		return i * i;
	};
	ll req = n;
	ll jump = n / 2;
	ll i = 0;
	while(1){
		cerr << i << ' ';
		if(f(i) > req){
			i -= jump;
		}
		else if(f(i) == req){
			break;
		}
		else{
			if(jump == 1){
				if(f(i + 1) > req){
					break ;
				}else{
					i += jump;
				}
			}else{
				i += jump;
			}
		}
		jump = (jump + 1) / 2;
	}
	cout << i << '\n';
	cerr << '\n' << n << '\n';
	cerr << 5952 * 5952 << '\n';
	cerr << 5953 * 5953 << '\n';
}