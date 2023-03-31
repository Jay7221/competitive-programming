FILE=$1
echo FILE=$FILE > .env
if [ ! -f $FILE.cpp ]
then
	cp 0.cpp $FILE.cpp
fi
