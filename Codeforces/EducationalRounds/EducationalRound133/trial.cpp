#include<iostream>
#include<string.h>
using namespace std;
int main(int argc, char* argv[]){
    for(int i = 0; i < argc; ++i){
        if(strcmp(argv[i], "ok")){
            cout << "OK\n";
        }else{
            cout << argv[i] << '\n';
        }
    }
    cout << '\n';
}