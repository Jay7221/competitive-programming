source .env
if [ ! -f $1.cpp ]
then
	cp 0.cpp $1.cpp
fi
echo SOLUTION=$SOLUTION > .env
echo GENERATOR=$1 >> .env
