#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
int popcount(int n){
	int a = 1;
	int ans = 0;
	while(a <= n){
		if(a & n){
			ans++;
		}
		a = a << 1;
	}
	return ans;
}
void brute(int a[], int n){
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			if(j == i){
			continue ;
		}
			for(int k = 0; k < n; k++){
				if(i == k || j == k){
			continue ;
		}
				for(int l = 0; l < n; l++){
					if(i == l || j == l || k == l){
						continue;
					}
					if(popcount(a[i] ^ a[j]) == popcount(a[k] ^ a[l])){
						cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << "\n";
						return ;
					}
				}
			}
		}
	}
	cout << -1 << "\n";
}
void solve(){
	int N;
	cin >> N;
	int a[N];
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	if(N <= 69){
		brute(a, N);
		return ;
	}
	vi found(32, -1);
	for(int i = 0; i < N - 1; i += 2){
		int z = popcount(a[i] ^ a[i + 1]);
		if(found[z] != -1){
			cout << found[z] + 1 << " " << found[z] + 2 << " ";
			cout << i + 1 << " " << i + 2 << "\n";
			return ;
		}
		found[z] = i;
	}

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	int N;
	while(T--){
		solve();
	}
	return 0;
}
