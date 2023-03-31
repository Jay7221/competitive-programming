FILE=$1
if [ ! -f $FILE.cpp ]
then
	cp 0.cpp $FILE.cpp
fi
echo FILE=$FILE > .env
