#include<iostream>
#include<algorithm>
using namespace std;
const long long MOD = 998244353;
int add(int a, int b){
	long long sum = a;
	sum = sum + b;
	sum = sum % MOD;
	return sum;
}
int mult(int a, int b){
	long long prod = a;
	prod = (prod * b) % MOD;
	return prod;
}
void solve()
{
	int n;
	cin >> n;
	int a[n];
	int ones = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		ones += (a[i] == 1);
	}
	sort(a, a + n);
	int ans = 1;
	for(int i = 0; i < n; ++i)
	{
		if((a[i] % 2 == 0) && (ones > 0))
		{
			--ones;
			a[i] += 1;
		}
		ans = mult(ans, a[i]);
	}
	cout << ans << '\n';
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