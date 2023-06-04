source .env
g++ -o $GENERATOR $GENERATOR.cpp
./$GENERATOR < inputf.in > outputf.out
