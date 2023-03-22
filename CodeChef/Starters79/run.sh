#! /bin/bash
source .env
g++ -o $FILE $FILE.cpp
./$FILE < inputf.in > outputf.out
cat outputf.out
