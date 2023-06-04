NUM_TESTCASES=$1
INPUT_DIR=input
OUTPUT_DIR=output
if [ ! -d $INPUT_DIR ] 
then
	mkdir $INPUT_DIR
fi

if [ ! -d $OUTPUT_DIR ]
then
	mkdir $OUTPUT_DIR
fi


g++ -o solution solution.cpp

for (( i = 0; i < $NUM_TESTCASES; ++i ))
do
	echo Generating testcases for testcase $i
	python3 generator.py > $INPUT_DIR/input00$i.txt
	echo Done generating test case for testcase $i
done


for (( i = 0; i < $NUM_TESTCASES; ++i ))
do
	echo Generating solution for testcase $i
	./solution < $INPUT_DIR/input00$i.txt > $OUTPUT_DIR/output00$i.txt
	echo Done generating solution for testcase $i
done
