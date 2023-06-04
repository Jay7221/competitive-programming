echo FILE=$1 > .env
if [ ! -d $FILE.cpp ]
then
    cp Problem.cpp $FILE.cpp
fi
