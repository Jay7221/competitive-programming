#include<bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k) {
	sort(arr, arr + n);
	int ans = arr[n - 1] - arr[0];
	for(int i = 1; i < n; ++i)
	{
		if(arr[i] < k)
		{
			continue;
		}
		int mx = max(arr[i - 1] + k, arr[n - 1] - k);
		int mn = min(arr[0] + k, arr[i] - k);
		ans = min(ans, mx - mn);
	}
	return ans;
}
int main()
{
	int k = 2;
	int n =  4;
	int arr[] = {1, 5, 8, 10};
	cout << getMinDiff(arr, n, k) << endl;
	return 0;
}
