#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	if((n % 2) == (m % 2))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}