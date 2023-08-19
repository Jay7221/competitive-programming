#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;
vector<int> gurdy(MAX), gurdy2(MAX);
void pre(){
    for(int i = 2; i < MAX; ++i){
        gurdy[i] = 1;
    }
    for(int i = 2; i < MAX; ++i){
        for(int j = 3; i * j < MAX; j += 2){
            if(gurdy[i] == gurdy[i * j]){
                ++gurdy[i * j];
            }
        }
    }
}
void pre2(){
    for(int i = 1; i < MAX; ++i){
        for(int j = 2; i * j < MAX; ++j){
            if(j % 2){
                if(gurdy2[i * j] == gurdy2[i]){
                    ++gurdy2[i * j];
                }
            }else{
                if(gurdy2[i * j] == 0){
                    ++gurdy2[i * j];
                }
            }
        }
    }
}
int main(){
    pre();
    pre2();
    for(int i = 1; i < MAX; ++i){
        if(gurdy[i] != gurdy2[i]){
            cout << i <<  "  : " << gurdy[i] << ' ' << gurdy2[i] << '\n';
        }
    }
}