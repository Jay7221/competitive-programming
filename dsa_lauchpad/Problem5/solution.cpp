#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int arr[N]={0};
        long long ans=0;
        int n=nums.size();
        int i=0,j=0;
        long long sum=0;
        while(j<n)
        {
            arr[nums[j]]++;
            sum+=nums[j];
            while(arr[nums[j]]>1)
            {
                arr[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            while(j-i+1>k)
            {
                sum-=nums[i];
                arr[nums[i]]--;
                i++;
            }
            if(j-i+1==k)
                ans=max(ans,sum);
            j++;
        }
        return ans;
    }
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	cout << maximumSubarraySum(a, k) << '\n';
}
int main(int argc, char **argv){
	if(argc > 1){
		freopen(argv[1], "r", stdin);
		freopen("solution.txt", "w", stdout);
	}
	solve();
	return 0;
};
