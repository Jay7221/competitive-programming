#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int a[4];
	for(int i = 0; i < 4; ++i){
		cin >> a[i];
	}
	sort(a, a + 4);
	if((a[0] == a[1]) && (a[2] == a[3])){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--){
		solve();
	}

	return 0;
}
