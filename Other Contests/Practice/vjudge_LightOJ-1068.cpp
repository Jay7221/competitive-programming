#include<bits/stdc++.h>
using namespace std;
const int noDigits = 10;
const int maxModVal = 10000;
const int maxDigitSum = 81;
const int noFlagVal = 2;
int dp[noDigits][maxDigitSum][maxModVal][noFlagVal];
vector<int> num;
int k;
int calc(int pos, int digitSum, int modVal, int flag)
{
	if(pos == num.size())
	{
		if((digitSum % k == 0) && (modVal == 0))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(dp[pos][digitSum][modVal][flag] != -1)
	{
		return dp[pos][digitSum][modVal][flag];
	}
	int ans = 0;
	if(flag)
	{
		int newDigitSum, newModVal;
		for(int digit = 0; digit < num[pos]; ++digit)
		{
			newDigitSum = digitSum + digit;
			newModVal = (modVal * 10 + digit) % k;
			ans += calc(pos + 1, newDigitSum, newModVal, 0);
		}
		for(int digit = num[pos]; digit <= num[pos]; ++digit)
		{
			newDigitSum = digitSum + digit;
			newModVal = (modVal * 10 + digit) % k;
			ans += calc(pos + 1, newDigitSum, newModVal, 1);
		}
	}
	else
	{
		int newDigitSum, newModVal;
		for(int digit = 0; digit < 10; ++digit)
		{
			newDigitSum = digitSum + digit;
			newModVal = (modVal * 10 + digit) % k;
			ans += calc(pos + 1, newDigitSum, newModVal, 0);
		}
	}
	return dp[pos][digitSum][modVal][flag] = ans;
}
void pre(int pos, int digitSum, int modVal, int flag)
{
	if(pos == num.size())
	{
		return ;
	}
	if(dp[pos][digitSum][modVal][flag] == -1)
	{
		return ;
	}
	dp[pos][digitSum][modVal][flag] = -1;
	int ans = 0;
	if(flag)
	{
		int newDigitSum, newModVal;
		for(int digit = 0; digit < num[pos]; ++digit)
		{
			newDigitSum = digitSum + digit;
			newModVal = (modVal * 10 + digit) % k;
			pre(pos + 1, newDigitSum, newModVal, 0);
		}
		for(int digit = num[pos]; digit <= num[pos]; ++digit)
		{
			newDigitSum = digitSum + digit;
			newModVal = (modVal * 10 + digit) % k;
			pre(pos + 1, newDigitSum, newModVal, 1);
		}
	}
	else
	{
		int newDigitSum, newModVal;
		for(int digit = 0; digit < 10; ++digit)
		{
			newDigitSum = digitSum + digit;
			newModVal = (modVal * 10 + digit) % k;
			pre(pos + 1, newDigitSum, newModVal, 0);
		}
	}
}
int get(int a, int k)
{
	// dp[pos][digitSum][modVal][flag] = number of nubmers with digitSum of prefix [1 : pos] equal to digitSum, value of prefix modulo k equal to modVal and prefix equal to prefix of a if flag is set or smaller than prefix of a
	num.clear();
	while(a > 0)
	{
		num.push_back(a % 10);
		a /= 10;
	}
	reverse(num.begin(), num.end());
	int pos, digitSum, modVal, flag;
	// for(pos = 0; pos < noDigits; ++pos)
	// {
	// 	for(digitSum = 0; digitSum < maxDigitSum; ++digitSum)
	// 	{
	// 		for(modVal = 0; modVal < maxModVal; ++modVal)
	// 		{
	// 			for(flag = 0; flag < noFlagVal; ++flag)
	// 			{
	// 				dp[pos][digitSum][modVal][flag] = -1;
	// 			}
	// 		}
	// 	}
	// }
	pre(0, 0, 0, 1);
	int ans = calc(0, 0, 0, 1);
	return ans;
}
void solve(int t)
{
	int a, b;
	cin >> a >> b >> k;
	cout << "Case " << t << ": ";
	// cout << get(b, k) << '\n';
	cout << (get(b, k) - get(a - 1, k)) << '\n';
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)
	{
		solve(i);
	}
	return 0;
}
