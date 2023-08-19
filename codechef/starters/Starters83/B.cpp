#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(){
	int A, B, C;
	cin >> A >> B >> C;
	int x = 0;
	int cas = 0;
	for(int k = 30; k >= 0; --k){
		int a = (A >> k) & 1;
		int b = (B >> k) & 1;
		int c = (C >> k) & 1;
		if(cas == 0){
			if((a == b) && (a == c)){
				continue;
			}
			if((b != a) && (b != c)){
				return -1;
			}
			if(b == c){
				if(c == 0){
					x ^= (1 << k);
				}
				cas = 1;
			}else{
				if(c == 0){
					x ^= (1 << k);
				}
				cas = 2;
			}
		}else if(cas == 1){
			if(b != c){
				if(c == 0){
					x ^= (1 << k);
				}
				return x;
			}
		}else if(cas == 2){
			if(a != b){
				if(b == 0){
					x ^= (1 << k);
				}
				return x;
			}
		}
	}
	A ^= x;
	B ^= x;
	C ^= x;
	if((A < B) && (B < C)){
		return x;
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		cout << solve() << '\n';
	}
}
