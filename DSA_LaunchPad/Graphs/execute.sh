#! /bin/bash

g++ -o main $1
./main < inputf.in > outputf.out
rm main
