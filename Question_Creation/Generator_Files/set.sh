FILE=$1_generator
if [ ! -f $FILE.cpp ] 
then
	cp generator.cpp $FILE.cpp
fi
echo FILE=$FILE > .env

