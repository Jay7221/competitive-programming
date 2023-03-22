FILE=$1
if [ ! -f $FILE.cpp ] 
then
	cp Problem0.cpp $FILE.cpp
fi
echo FILE="$1" > .env
