source .env
echo SOLUTION=$1 > .env
if [ ! -f $1.cpp ]
then
	cp 0.cpp $1.cpp
fi
echo GENERATOR=$GENERATOR >> .env
