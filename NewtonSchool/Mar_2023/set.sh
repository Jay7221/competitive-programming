FILE=$1
if [ ! -f $FILE.cpp ]
then
	cp A_0.cpp $FILE.cpp
fi
echo FILE=$FILE > .env
