

if [ $1 ]
then
	file="$1"
	g++ -o main $file
	./main < inputf.in > outputf.out
	rm main
fi
