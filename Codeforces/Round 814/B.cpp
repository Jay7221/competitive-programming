#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	k = k % 4;

	if(k == 0){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	int cur = 1;
	if(k % 2){
		for(cur = 1; cur < n; cur += 2){
			cout << cur << ' ' << cur + 1 << '\n';
		}
	}else{
		for(cur = 1; cur + 3 <= n; cur += 4){
			cout << cur + 1 << ' ' << cur + 0 << '\n';
			cout << cur + 2 << ' ' << cur + 3 << '\n';
		}
		if(n % 4 == 2){
			cout << n << ' ' << n - 1 << '\n';
		}
	}
	// vector<int> arr = {0, 1, 2, 3};
	// auto ok = [&](){
	// 	int a = 1 + arr[0], b = 1 + arr[1], c = 1 + arr[2], d = 1 + arr[3];
	// 	if(((a + k) * b) % 4){
	// 		return 0;
	// 	}
	// 	if(((c + k) * d) % 4){
	// 		return 0;
	// 	}
	// 	return 1;
	// };
	// while(!ok()){
	// 	next_permutation(arr.begin(), arr.end());
	// }
	// int cur = 1;
	// for(cur = 1; cur + 4 < n; cur += 4){
	// 	int a = cur + arr[0], b = cur + arr[1], c = cur + arr[2], d = cur + arr[3];
	// 	cout << a << ' ' << b << '\n';
	// 	cout << c << ' ' << d << '\n';
	// }
	// if(n % 4 == 2){
	// 	int a = n - 1, b = n;
	// 	if(((a + k) * b) % 4)
	// 		swap(a, b);
	// 	cout << a << ' ' << b << '\n';
	// }
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}