#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> nums = {3, 2, 4};
	int target = 6;
	vector<int> a = nums;
        sort(a.begin(), a.end());
        int i = 0, j = a.size() - 1;
        while(a[i] + a[j] != target && i < j){
            if(a[i] + a[j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        vector<int> ans(2);
        int k = 0;
        for(int l = 0; l < nums.size(); l++){
            if(nums[l] == a[i] || nums[l] == a[j]){
                ans[k] = l;
                k++;
            }
        }
        for(auto c : ans ){
        	cout << c << ' ' ;
        }
}