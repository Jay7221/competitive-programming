#include<iostream>
using namespace std;
int main(){
	int L;
	cin >> L;
	char c;
	int Nutan = 0, Tusla = 0;
	while(L--){
		cin >> c;
		if(c == 'N'){
			Nutan++;
		}else{
			Tusla++;
		}
	}
	if(Nutan > Tusla){cout << "Nutan";}
	else{cout << "Tusla";}
}