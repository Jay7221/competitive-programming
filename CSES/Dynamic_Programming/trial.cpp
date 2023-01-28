#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, x;
	cin>>n>>x;
	int nums[n];
	for(int i=0;i<n;i++)
	{
	    cin>>nums[i];
	}
	int dp[x+1]={0};
	dp[0]=1;
	for(int i=1;i<=x;i++)
	{
	    int count=0;
	    for(int j=0;j<n;j++)
	    {
	        if(i-nums[j]>=0) 
	            count=(count+dp[i-nums[j]])%mod;
	    }
	    dp[i]=count;
	}
	cout<<dp[x]<<endl;
	return 0;
}