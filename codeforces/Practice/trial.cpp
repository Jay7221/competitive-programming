#include<iostream>
using namespace std;
int noDiv(int n)
{
	int ans = 0;
	for(int i = 1; i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			++ans;
			if(i * i != n)
			{
				++ans;
			}
		}
	}
	return ans;
}
int main()
{
	int maxDiv = 0;
	int MAX = 1e6 + 7;
	for(int i = 1; i <= MAX; ++i)
	{
		maxDiv = max(maxDiv, noDiv(i));
	}
	for(int i = 1; i <= MAX; ++i)
	{
		if(noDiv(i) == maxDiv)
		{
			cout << i << '\n';
		}
	}
	cout << maxDiv << '\n';
}
