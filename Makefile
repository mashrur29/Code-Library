all:
	g++ -std=c++11 main.cpp -o main
	echo "--------- Test Input ----------" > output.txt
	echo "" >> output.txt
	./main < input.txt >> output.txt
	echo "" >> output.txt
	echo "--------- Input1 ----------" >> output.txt
	echo "" >> output.txt
	./main < input1.txt >> output.txt
	echo "" >> output.txt
	echo "--------- Input2 ----------" >> output.txt
	echo "" >> output.txt
	./main < input2.txt >> output.txt
	echo "" >> output.txt
	echo "--------- Input3 ----------" >> output.txt
	echo "" >> output.txt
	./main < input3.txt >> output.txt
