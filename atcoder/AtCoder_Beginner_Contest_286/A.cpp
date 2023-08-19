#include<iostream>
using namespace std;
int main()
{
	int n;
	int p, q, r, s;
	cin >> n;
	cin >> p >> q >> r >> s;
	int a[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	--p, --q, --r, --s;
	for(int i = 0; i < q - p + 1; ++i)
	{
		swap(a[i + p], a[i + r]);
	}
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ' ;
	}
	cout << '\n';
	return 0;
}