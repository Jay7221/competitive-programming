#include<bits/stdc++.h>
using namespace std;
#define ll long long
int F[46];
bool solve(){
	int n, x, y;
	cin >> n >> x >> y;
	while(n > 0){
		if((x > F[n]) || (y > F[n + 1])){
			return false;
		}
		x = min(x, F[n] - x  + 1);
		y = min(y, F[n + 1] - y + 1);
		swap(x, y);
		--n;
	}
	return true;
}
void pre(){
	F[0] = F[1] = 1;
	for(int i = 2; i < 46; ++i){
		F[i] = F[i - 1] + F[i - 2];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pre();
	int t;
	cin >> t;
	while(t--){
		if(solve()){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}

	return 0;
}
