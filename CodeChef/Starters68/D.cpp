#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n], ans[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 0, j = 1; i < n / 2; ++i, j += 2)
	{
		ans[j] = a[i];
	}
	for(int i = n / 2, j = 0; i < n; ++i, j += 2)
	{
		ans[j] = a[i];
	}
	bool flag = true;
	for(int i = 1; i < n - 1; ++i){
		if((ans[i] >= ans[i - 1]) && (ans[i] <= ans[i + 1])){
			flag = false;
		}
		if((ans[i] <= ans[i - 1]) && (ans[i] >= ans[i + 1])){
			flag = false;
		}
	}
	if(!flag){
		cout << -1 << '\n';
		return ;
	}
	for(int i = 0; i < n; ++i)
	{
		cout << ans[i] << ' ' ;
	}
	cout << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}