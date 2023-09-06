#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int freq[n + 1] = {0};
	for(int i = 0; i < n;++i){
		int a;
		cin >> a;
		++freq[a];
	}
	if(n % 2){
		cout << n << '\n';
	}
	else{
		int count = 0;
		for(int i = 0; i < n + 1; ++i){
			if(freq[i] >= n / 2){
				++count;
			}
		}
		if(count > 1){
			cout << (n / 2) + 1 << '\n';
		}else{
			cout << n << '\n';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}