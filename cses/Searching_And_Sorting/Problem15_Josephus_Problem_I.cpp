#include<iostream>
#include<vector>
int main(){
	int n;
	std::cin >> n;
	std::vector<int> v, ans;
	for(int i = 1; i <= n; ++i){
		v.push_back(i);
	}
	bool flag = 0;
	while(v.size()){
		std::vector<int> tmp;
		for(auto elem : v){
			if(flag){
				ans.push_back(elem);
			}else{
				tmp.push_back(elem);
			}
			flag ^= 1;
		}
		v = tmp;
	}
	for(auto elem : ans){
		std::cout << elem << ' ';
	}
	std::cout << '\n';
}