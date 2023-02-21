#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll even, odd;
	cin >> even >> odd;
	ll total = even + odd;
	ll k = 1;
	auto check = [&](ll numCompenents)
	{
		if(total % numCompenents != 0)
		{
			return false;
		}
		ll sizeComponent = total / numCompenents;
		if(sizeComponent == 1)
		{
			if((even == 0) or (odd == 0))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if(odd % numCompenents == 0)
		{
			return true;
		}
		else
		{
			if((odd % 2 == 1) && (numCompenents % 2 == 0))
			{
				return false;
			}
			ll new_odd = odd % numCompenents;
			if(new_odd % 2 == 1)
			{
				if(odd < numCompenents)
				{
					return false;
				}
				new_odd += numCompenents;
			}
			if(even < 2 * (numCompenents - (new_odd / 2)))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	};
	for(ll d = 1; d * d <= total; ++d)
	{
		if(check(d))
		{
			k = max(k, d);
		}
		if(check(total / d))
		{
			k = max(k, total / d);
		}
	}
	cout << k << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	t = 1;
	while(t--)
	{
		solve();
	}

	return 0;
}